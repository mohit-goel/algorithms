
#include<stdio.h>
#include<conio.h>

int rotatedBinSearch(int array[], int val, int size);
main()
{
      int  arr[]={15,16,19,20,25,1,3,4,5,7,10,13};
      
      //scanf("%[" "]s",arr);
    //  printf("%s",arr);
      int j =rotatedBinSearch(arr,20,12);
       printf("%d",j);
      //reverse(j,arr);
     
      getch();
      return 0;
      }
      
      



int rotatedBinSearch(int array[], int val, int size) {

int beg = 0;
int end = size-1;
int mid = 0;

while (beg <= end) {

mid =  (end-beg)/2;
printf("mid %d  ",mid);
printf("beg %d  ",beg);
printf("end %d  ",end);
if (array[mid] == val) return mid;

if (array[end] < val) //look for left section 
{
end = mid-1;
}
else if (array[beg] > val) //look for right section 
{
beg = mid+1;

}
else { //do normal binary search
if (array[mid] < val) {

beg = mid+1;

}
else {
end = mid-1;
}
}
}//end while

return -1;
}
