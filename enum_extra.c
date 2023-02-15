#include <stdio.h>
enum day {sunday = 3, tuesday, wednesday, thursday = 2, friday, saturday};

int main()
{
	enum day d1 = sunday;
  	enum day d2 = tuesday;
	enum day d3 = wednesday;
	enum day d4 = thursday;
	enum day d5 = friday;
	enum day d6 = saturday;

  	
	printf("The day number stored in d is %d\n", d1);
	printf("The day number stored in d is %d\n", d2);
	printf("The day number stored in d is %d\n", d3);
	printf("The day number stored in d is %d\n", d4);
	printf("The day number stored in d is %d\n", d5);
	printf("The day number stored in d is %d\n", d6);
	return 0;
}
