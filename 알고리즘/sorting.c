#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define file_name "Sample Data.txt"
#define SWAP(x, y, t) t = x, x = y, y = t

void arrayPrint();
void sort();
void readFile();
void quicksort(int start, int end);

int count = 1; //정수의 총 갯수
int *array;    //배열 정렬 및 출력을 위한 전역변수 선언

int main(void)
{
    readFile();
    sort();
    arrayPrint();

    return 1;
}

void readFile()
{
    FILE *fp = fopen(file_name, "r"); //파일 읽기형식으로 열기
    int i = 0, c;
    char *token = ",";

    if (fp == NULL) //오류 처리
    {
        printf("No Data File!");
    }

    do
    {
        c = fgetc(fp);
        if (c == ',')
        {
            count++;
        }
    } while (c != EOF); //','의 갯수 +1을 통해 정수의 갯수 확인

    array = (int *)malloc(count * sizeof(int)); //파일 안의 정수 갯수만큼 배열 생성

    rewind(fp); //파일포인터 초기화

    while (!feof(fp)) //파일의 끝이 올떄까지
    {
        fscanf(fp, "%d, ", &array[i]); //배열에 입력
        i++;
    }

    fclose(fp); //파일닫기
}

void sort() //퀵 정렬
{
    quicksort(0, count - 1);
}

void quicksort(int start, int end)
{
    if (start >= end) // 1개의 값만 남아있다면 바로 종료
    {
        return;
    }

    int key = start; //피봇을 첫 값으로 설정
    int i = start + 1;
    int j = end;
    int temp; //교환을 위한 변수

    while (i <= j) // i와 j가 역전될때까지 반복
    {
        while (array[i] <= array[key]) //피봇보다 i위치의 값이 작다면 i위치 다음으로 이동
        {
            i++;
        }

        while (array[j] > array[key] && j > start) //피봇보다 j위치의 값이 크다면 j위치 이전으로 이동
        {
            j--;
        }

        if (i > j) // i의 위치가 j보다 크다면 피봇과 j의 값을 교환
        {
            temp = array[j];
            array[j] = array[key];
            array[key] = temp;
        }
        else //그 외의 경우 i의 값과 j의 값을 교환
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    quicksort(start, j - 1); //피봇의 값이 들어있는 j의 위치를 기준으로 좌우를 퀵정렬
    quicksort(j + 1, end);
}

void arrayPrint()
{
    for (int i = 0; i < count; i++)
    {
        printf("%5d\t", array[i]);
    }
}