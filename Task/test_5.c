#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 1
#define FAIL 0
#define MAX_RECORD 10
#define NAME_MAX_LEN 20
#define MAX_STATUS_STRING 8
#define MAX_FIELDS 5

enum Field { Status = 1 , Name , MessageWaitFlag , VMS_MessageWaitFlag , BacklightTimer, };
enum setStatus { Disable, Enable, };
char DKP_Types[5][10] = { "DKP 45", "DKP 65", "DKP 42S", "DKP 42P", "DKP 48", };
char stat[2][10] = { "Disable","Enable", };

//For date and time, take a structure representing Date, Month, Year, Hour, Minute, and Second; and write this structure in the start of the file.

struct timingInfo
{
    char date[14];
    char time[14];
};

int writeDateTime(struct timingInfo* ptr)
{   
    if(NULL==ptr)
    {
        printf("[%s]:[%d] NULL pointer detected as timingInfo structure pointer\n", __func__, __LINE__);
        return 1;
    }
    char date[] = __DATE__;
    char time[] = __TIME__;
    int index = 0;
    while(date[index] != 0)
    {
        ptr->date[index] = date[index];
        index++; 
    }
    index = 0;
    while(time[index] != 0)
    {
        ptr->time[index] = time[index];
        index++; 
    }
    return 0;
}

struct DKP_Parameters
{

    char Status[MAX_STATUS_STRING];
    char Name[NAME_MAX_LEN];
    unsigned MessageWaitFlag : 1 ;
    unsigned VMS_MessageWaitFlag : 1 ;
    unsigned BacklightTimer : 8 ;    // status Enable/Disable

};

void* memoryAlloc(int recordSize, int recordCount)
{   
    
    struct DKP_Parameters *records = ( struct DKP_Parameters* )malloc(recordCount*recordSize);
    if(NULL==records)
    {
        printf("[%s]:[%d] NULL pointer detected (Unable to allocate memory )\n", __func__, __LINE__);
        exit(1);
    }
    return records;
}

void allocDB(struct DKP_Parameters *ptr, int recordSize, int recordCount)
{   
    if(NULL==ptr)
    {
        printf("[%s]:[%d] NULL pointer detected as Master Database pointer\n", __func__, __LINE__);
        exit(1);
    }
    ptr = ( struct DKP_Parameters* )malloc(recordSize*recordCount);
}

void memoryDealloc( struct DKP_Parameters *ptr)                                                         // dealloc Database
{
    free(ptr);
    ptr = NULL;
}

int deallocDB( struct DKP_Parameters *ptr)                                                              // dealloc Maser Database
{
    if(NULL==ptr)
    {
        printf("[%s]:[%d] NULL pointer detected as Master Database pointer\n", __func__, __LINE__);
        return 1;
    }
    free(ptr);
    ptr = NULL;
    return 0;
}

void setStatus( struct DKP_Parameters *ptr)
{   
    int sIndex;
    printf("Enter 1 to set Enable OR 0 to set Disable \n");
    scanf("%d",&sIndex);
    if( sIndex != 0 && sIndex != 1)
    {   
        printf("Invalid Input, Default Value Taken as 0 \n");
        sIndex = 0;
    }
    for(int index = 0 ; index < MAX_STATUS_STRING ; index++)
    {
        ptr->Status[index] = stat[sIndex][index]; 
    }
}

void setName( struct DKP_Parameters *ptr)
{   
    char name[NAME_MAX_LEN];
    printf("Enter Name ( MAX characters allowed = 20):\n");
    scanf("%s", name);
    if(strlen(name)>20)
    {   
        printf("Invalid Name : Entered String is having more than 20 characters string ! \n ");
        exit(1);
    }
    for(int index = 0 ; index < NAME_MAX_LEN ; index++)
    {
        ptr->Name[index] = name[index]; 
    }
}

void setMessageWaitFlag( struct DKP_Parameters *ptr)
{   
    int flag ;
    printf("Enter MessageWaitFlag Value (0 or 1):\n");
    scanf("%d", &flag);
    if( flag != 0 && flag != 1)
    {   
        printf("Invalid Input, Default Value Taken as 0 \n");
        flag = 0;
    }
    ptr->MessageWaitFlag = flag; 
}

void setVMS_MessageWaitFlag( struct DKP_Parameters *ptr)
{   
    int flag ;
    printf("Enter VMSmessageWaitFlag Value (0 or 1):\n");
    scanf("%d", &flag);
    if( flag != 0 && flag != 1)
    {   
        printf("Invalid Input, Default Value Taken as 0 \n");
        flag = 0;
    }
    ptr->VMS_MessageWaitFlag = flag;
}

void setBacklightTimer( struct DKP_Parameters *ptr)
{   
    int timer ;
    printf("Enter 8 Bit Timer Parameter (0 - 255):\n");
    scanf("%d", &timer);
    if( timer < 0 || timer > 255)
    {   
        printf("Invalid Input, Default Value Taken as 0 \n");
        timer = 0;
    }
    ptr->BacklightTimer = timer;
}

void set( enum Field fSelect, struct DKP_Parameters *ptr )
{
    switch (fSelect)
    {
        case Status:
            setStatus(ptr);
            break;
        case Name:
            setName(ptr);
            break;
        case MessageWaitFlag:
            setMessageWaitFlag(ptr);
            break;
        case VMS_MessageWaitFlag:
            setVMS_MessageWaitFlag(ptr);
            break;
        case BacklightTimer:
            setBacklightTimer(ptr);
            break;
    }
}

/*saveRecord()
Input: record pointer, record index i
Process: write this record in file at its place or index. Use fseek here.
Output: 0 (failed) or 1 (success)
*/

int saveRecoed(char *fileName, struct DKP_Parameters *record, int offset, FILE *fptr)
{   
    int valid = 0;
    if ((fptr = fopen(fileName, "r+")) == NULL) {
		printf("Error! opening file");
		// If file pointer will return NULL return 1 
		return 1;
	}
    struct timingInfo *tPtr;   // creating pointer to structure for time/date Information.
    tPtr = (struct timingInfo*)malloc(sizeof(struct timingInfo)*1);

    valid = writeDateTime(tPtr);
    if( valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;
    }

    fwrite(tPtr, sizeof(struct timingInfo), 1, fptr);
    free(tPtr);
    tPtr = NULL ;
    valid = fseek(fptr, offset*(sizeof(struct DKP_Parameters)), SEEK_CUR);
    fwrite(record+offset, sizeof(struct DKP_Parameters), 1, fptr);
	fclose(fptr);
	return 0;
}

int addRecord (struct DKP_Parameters *record, int index, char *fileName, FILE *fptr)
{
    int valid = 0;
    if(NULL==record+index)
    {
        printf("[%s]:[%d] Unable to allocate memory \n", __func__, __LINE__);
        return 1;
    }
    for(enum Field setField = Status ; setField <= MAX_FIELDS ; setField++)
    {
        set(setField,record+index);
    }
    valid = saveRecoed(fileName,record,index,fptr);                             // saving each record to file after adding data to each (index = offset for fseek)
    if( valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;
    }
    return 0;
}

/*createFile(): Create a file using file operations
Input: File Name
Process:
The first data of the file will be the last updated date and time of the File.
If date is already written, it should be overwritten.
Output: 0 (failed) or 1 (success)*/

int createFile(char * fileName, FILE *fptr ) 
{
   
	if ((fptr = fopen(fileName, "w")) == NULL) {
		printf("Error! opening file");
		// If file pointer will return NULL return 1 
		return 1;
	}
    struct timingInfo *tPtr;   // creating pointer to structure for time/date Information.
    tPtr = (struct timingInfo*)malloc(sizeof(struct timingInfo)*1);

    int valid = writeDateTime(tPtr);
    if( valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;
    }

    fwrite(tPtr, sizeof(struct timingInfo), 1, fptr);
    free(tPtr);
    tPtr = NULL ;
    
	fclose(fptr);
	return 0;
}

/*defaultRecord()
Input: record pointer
Process: Set all zeros to memory located pointed to by the record pointer.
Output: 0 (failed) or 1 (success)*/

int defaultRecord(struct DKP_Parameters *ptr)
{
    if(NULL == ptr)
        {
            printf("[%s]:[%d] Null Detected as ptr \n", __func__, __LINE__);
            return 1;
        }
    memset(ptr->Status,0,sizeof(ptr->Status));
    memset(ptr->Name,0,sizeof(ptr->Name));
    ptr->MessageWaitFlag = 0;
    ptr->VMS_MessageWaitFlag = 0;
    ptr->BacklightTimer = 0;
    return 0;
}

int updateRecord(int recIndex, struct )
{
//----------------------remaining-------------------------
};

int main()
{
//-----------------------INPUTS---------------------------
    int recordSize = sizeof(struct DKP_Parameters);
    int recordCount;
    int recIndex = 0;
    int valid = 0;
    
    printf("Enter Number of Recoeds you want to store [MAX Limit = 10]:\n");
    scanf("%d", &recordCount);                                                          // Enter recordcount = 2 to verify 

    if( recordCount > 10 )
    {
        printf("Count Limit exceeded \n");
    }

    struct DKP_Parameters *records = (struct DKP_Parameters*)memoryAlloc(recordSize,recordCount);

    char fileName[] = "myfile.txt";
    FILE *fptr;                                   // creating file pointer in main() to have access to the file created throughout main() execution
    valid = createFile(fileName,fptr);
    if( valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;
    }
    
    for( recIndex = 0 ; recIndex < recordCount ; recIndex++)    // Taking Input Values for N records using for Loop 
    {
        valid = addRecord(records, recIndex, fileName, fptr);

        if( valid == 1)
        {
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;
        }
    }

    // valid = defaultRecord(records + 1);      // set all record fields to 0 by providing offstet index (Here 1 is offset to 2nd struct)
    
    // valid = saveRecoed(fileName,records,1,fptr);
    // if( valid == 1)
    // {
    //     printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
    //     return 1;
    // }

}
