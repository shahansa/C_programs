
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

#define DURATION(start, end) (end.tv_usec-start.tv_usec)+((end.tv_sec-start.tv_sec)*1000000)

int main()
{
	int fd1 = open("wiki.html", O_RDWR);
	if(fd1 < 0)
		return 0;
	int fd2 = open("wiki.html", O_RDWR);
	char c1,c2;
struct timeval start_time, end_time;
/* store the starting time */
	gettimeofday(&start_time, NULL);
	lseek(fd2,-1,SEEK_END);
		read(fd1,&c1,1);
		read(fd2,&c2,1);
	while( c1!= c2)
	{
		lseek(fd1,-1,SEEK_CUR);
		lseek(fd2,-1,SEEK_CUR);
		write(fd1,&c2,1);
		write(fd2,&c1,1);
		lseek(fd2,-2,SEEK_CUR);
		read(fd1,&c1,1);
		read(fd2,&c2,1);
		
	}
		
/* store the finishing time */
	gettimeofday(&end_time, NULL);
	printf("%lu",DURATION(start_time,end_time));

	return 0;
}
	



