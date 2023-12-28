#include <stdio.h>
#include <string.h>

int n;
char time[101][100], long_lat[101][200];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &time[i]);
        scanf("%s", &long_lat[i]);
    }
    for(int i = 0; i < n; i++){
    	char *p_1 = strstr(long_lat[i], "longitude");
    	char *p_2 = strstr(long_lat[i], "latitude");
    	int tmp_1 = p_1 - long_lat[i], tmp_2 = p_2 - long_lat[i];
    	
    	if(p_1 == NULL || p_2 == NULL){
    		printf("01/01/1970 00:00:00 AM");
    		return 0;
		}
    	
    	else if(long_lat[i][tmp_1 + 11] != "0" && long_lat[i][tmp_2 + 10] != "0"){
    		printf("%s", time[i]);
    		return 0;
		}
	}
	printf("01/01/1970 00:00:00 AM");
}
