---
title: 封装的库函数函数
date: 2022-12-22 19:53:12
tags:  库 函数
---

# 封装的一些库函数

## 目标

学习了B站大佬的 `http://www.freecplus.net/` 网站，自己动手封装了一些库函数

头文件： _pub.h

``` c
#include <time.h>

// 求绝对值的函数
int ABS(const int i);					//int求绝对值
long LABS(const long int i);	//long求绝对值

// char to int
int CTOI(const char c);	//字符转化为数字

// pow
unsigned long long POW(const unsigned long int x, const long int y);	//求幂

// nptr to int 
int ISSPACE(const char ch);
int ATOI(const char* nptr);	// 把字符串转化为int
long ATOL(const char* nptr);	//把字符串转化为long
double ATOD(const char* nptr);

//字符串操作一系列函数
int ISALPHA(int ch);	//若ch是字母字符'a-z'或者'A-Z' 返回非0值，否则返回0
int ISALNUM(int ch);	//若ch是字母字符'a-z', 'A-Z' 或者数字字符'0-9' 返回非0值，否则返回0
int ISDIGIT(int ch);	//若ch是数字'0-9' 返回非0值，否则返回0
int ISLOWER(int ch);	//若ch是小写字母'a-z' 返回非0值，否则返回0
int ISUPPER(int ch);	//若ch是大写字母'A-Z' 返回非0值  否则返回0
int TOLOWER(int ch);	//若ch是大写字母'A-Z' 转化为对应小写字母 返回其ASCALL码
int TOUPPER(int ch);	//若ch是小写字母'a-z' 转化为对应大写字母 返回其ASCALL码

//浮点数的一系列函数
double FABS(const double x);	// 求双精度实数x的绝对值
double ROUND(const double x);	// double四舍五入
double CEIL(const double x);	// double向上取整数
double FLOOR(const double x);	// double向下取整数
//把双精度val分解成整数部分和小数部分，整数部分存放在ip所指的变量中，返回小数部分
double MODF(double val,double *ip);

/***字符串一系列函数***/
typedef unsigned long size_t;
char *MEMSET(char* str, size_t index, size_t size);	//字符串置位函数
size_t STRLEN( const char*  str);          // 实现strlen函数的功能
char *STRCPY(char* dest, const char* src);  // 实现strcpy函数的功能，下同。
char *STRNCPY(char* dest, const char* src,size_t n);
char *STRCAT(char* dest, const char* src);
char *STRNCAT(char* dest, const char* src,size_t n);
char *STRCHR(const char *s, const int c);
char *STRRCHR(const char *s, const int c);
// 字符串比较函数
int STRCMP(const char *str1, const char *str2);
int STRNCMP(const char *str1, const char * str2, const size_t n);
// 判断字符串
void ToUpper(char *str);	//小写字母转大写 忽略其他字符
void ToLower(char *str);	//大写字母转小写 忽略其他字符
int IsDigit(const char *str);	//判断内容是否全是数字 1-是 0-不是
int IsUpper(const char *str);	//判断内容是否全是大写字母 1-是 0-不是
int IsLower(const char *str);	//判断字符是否全是小写字母 1-是 0-不是
int IsASCLL(const char *str); //判断是否全是ASCLL字符 1-是 0-不是
// KMP算法重写快速匹配 -- 暂时实现的是暴力破解BF算法
char* STRSTR(const char* str1, const char* str2);



//********************************XML解析**************************************
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);

/*********************************时间转换**************************************/
int TIMETOSTR(const time_t ti,char *strtime);			//把整数的时间转换为字符串格式的时间
int STRTOTIME(const char *strtime,time_t *ti);		//把字符串格式的时间转换为整数的时间
void LOCALTIME(char *out_stime,const char *in_fmt,const int in_interval);	//获取操作系统的时间

```

源文件： _pub.c

```c
#include <stdio.h>
#include "_pub.h"

#ifndef NULL
#define NULL ((void *)0)
#endif


// ABS
int ABS(const int i)
{
	int ret;
	if (i >= 0) 
		ret = i;
	else 
		ret = (-1) * i;
	return ret;
}

long LABS(const long int i)
{
	long ret;
	if (i >= 0)
		ret = i;
	else
		ret = (-1) * i;
	return ret;
}

// char to int
int CTOI(const char c)
{
	if(c < 48 && c > 57)
		return -1;
	return c - 48;
}

// POW
unsigned long long  POW(const unsigned long int x,const long int y)
{
	long result = 1, base = x, index = y;
	while(index)
	{
		if(index % 2 == 1)
			result *= base;
		base *= base;
		index /= 2;
	}
	return result;
}

//判断是否有空格
int ISSPACE(const char ch)
{
	if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\f' || ch == '\v' || ch == '\r')
		return 1;
	return 0;
}


/************* ATOI && ATOL*************************/
int ATOI(const char *nptr)	// string to int
{
	char sign;
	char sign_1 = *nptr;
	int nValue = 0;

	while(ISSPACE(*nptr))
		nptr++;		//去空格

	sign = *nptr;
	if(!ISDIGIT(sign))
		nptr++;

	while(ISDIGIT(*nptr))
	{
		nValue = 10 * nValue + (*nptr - '0');
		nptr++;
	}

	return sign_1 == '-'? -nValue:nValue;
}

long ATOL(const char * nptr)	// string to long
{
	char sign;
	char sign_1 = *nptr;
	long nValue = 0;

	while(ISSPACE(*nptr))
		nptr++;		//去空格

	sign = *nptr;
	if(!ISDIGIT(sign))
		nptr++;

	while(ISDIGIT(*nptr))
	{
		nValue = 10 * nValue + (*nptr - '0');
		nptr++;
	}

	return sign_1 == '-'? -nValue:nValue;
}

double ATOD(const char* nptr)
{
	char sign;
	int point = 0;
	char sign_1 = *nptr;
	int nValue = 0;

	while(ISSPACE(*nptr))
		nptr++;		//去空格

	sign = *nptr;
	if(!ISDIGIT(sign) && sign != '.')
		nptr++;
	
	while(ISDIGIT(*nptr))
	{
		if(sign == '.')
		{
			nptr++;
			point++;
			nValue = POW(10,-point) * nValue + (*nptr -'0');
		}
		else
		{
			nValue = 10 * nValue + (*nptr - '0');
			nptr++;
		}
	}
	return sign_1 == '-'? -nValue:nValue;	
}

/******************字符操作一些列函数****************/
int ISALPHA(int ch)
{
	if(ch >= 97 && ch <= 122)
		return ch - 96;
	else if(ch >= 65 && ch <= 90)
		return ch - 64;
	return 0;
}

int ISALNUM(int ch)
{
	if(ch >= 97 && ch <= 122)
		return ch - 96;
	else if(ch >= 65 && ch <= 90)
		return ch - 64;
	if(ch >= 48 && ch <= 57)
		return ch - 47;
	return 0;
}

int ISDIGIT(int ch)
{
	if(ch >= 48 && ch <= 57)
		return ch - 47;
	return 0;
}

int ISLOWER(int ch)
{
	if(ch >= 97 && ch <= 122)
		return ch - 96;
	return 0;
}

int ISUPPER(int ch)
{
	if(ch >= 65 && ch <= 90)
		return ch - 64;
	return 0;
}

int TOLOWER(int ch)
{
	if(ch >= 65 && ch <= 90)
		return ch + 32;
	return 0;
}

int TOUPPER(int ch)
{
	if(ch >= 97 && ch <= 122)
		return ch - 32;
	return 0;
}
/***************** 浮点数一系列函数***************/
double FABS(const double x)	//求双精度实数x的绝对值
{
	double a = x;
	if(x < 0)
		a *= (-1);
	return a;
}
double ROUND(const double x)//double四舍五入
{
	int a = x;
	double b = x - a;
	if(b > 0.5)
		a += 1;
	return a;
}
double CEIL(const double x)	//double向上取整数
{
	int a = x;
	a += 1;
	return a;
}
double FLOOR(const double x)	// double向下取整数
{
	int a = x;
	return a;
}
double MODF(double val,double *ip)
{
	// 把双精度val分解成整数部分和小数部分，整数部分存放在ip所指的变量中，返回小数部分
	int a = val;
	double d = val - a;
	double da = val - d;
	*ip = da;
	return d;
}

/***************字符串一系列函数*********************/
size_t STRLEN(const char * str)
{
	const char * str1 = str;
	size_t len = 0;
	while(*str1 != '\0')
		if(*str1 != '\n')
			str1++;
	len = str1 - str;
	return len;
}
//置位函数
char * MEMSET(char * str, size_t index, size_t size)
{
	if(index < 0 || str == NULL)
		return NULL;		
	while(size-- > 0)
		*str++ = index;	
	return str;
}
//修改字符串指针指向
char *STRCPY(char* dest, const char* src)
{
	int i;
	for(i = 0; i < STRLEN(src); i++)
	{
		dest[i] = src[i];	
	}
	return dest;
}
char *STRNCPY (char* dest, const char* src,size_t n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return dest;	
}

// 字符串拼接
char *STRCAT(char * dest, const char * src)
{
	char * str1 = dest;
	long len = STRLEN(src);
	long len_d = STRLEN(dest);
	int i;
	for(i = 0; i < len; i++)
	{
		str1[len_d] = src[i];
		len_d++;
	}
	return str1;
}

char *STRNCAT (char* dest,const char* src, const size_t n)
{
	char * str1 = dest;
	long len_d = STRLEN(dest);
	int i;
	for(i = 0; i < n; i++)
	{
		str1[len_d] = src[i];
		len_d++;
	}
	return str1;
}

char *STRCHR(const char *s,const int c)
{
	
	char * sb = (char *) s;
	int len = STRLEN(s);
	int i = 0;
	
	while(i < len)
	{
		if(*sb == c)
			break;	
		sb++;
		i++;
	}
	if(i == len)
		return "(null)";
	return sb;
}

char *STRRCHR(const char *s, const int c)
{
	int len = STRLEN(s);
	char * sb = (char *) (s+len-1);
	int i = 0;
	
	while(i < len)
	{
		if(*sb == c)
			break;
		sb--;
		i++;
	}

	if(i == len)
		return "(null)";
	
	return sb;
	
}

//====================字符串比较函数=====================
int STRCMP(const char *str1, const char *str2)
{
	size_t len = STRLEN(str1)>STRLEN(str2)?STRLEN(str1):STRLEN(str2);
	while(len--)
	{
		if(*str1 != *str2)
			return (*str1)-(*str2);
		str1++;
		str2++;
	}
	return 0;
}
int STRNCMP(const char *str1, const char *str2, size_t n)
{
	while(n--)
	{
		if(*str1 != *str2)
			return (*str1) - (*str2);
		str1++;
		str2++;
	}
	return 0;
}
// 判断字符串
void ToUpper(char *str)	//小写字母转大写 忽略其他字符
{	
	while(*str != '\0')
	{
		if(*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
		
}
void ToLower(char *str)	//大写字母转小写 忽略其他字符
{
	for(str; *str != '\0'; str++)
		if(*str >= 65 && *str <= 90)
			*str += 32;
}
int IsDigit(const char *str)	//判断内容是否全是数字 1-是 0-不是
{
	int flag = 0;
	for(str; *str != '\0'; str++)
	{
		if(*str >= 48 && *str <= 57)
		{
			flag = 1;
			continue;
		}
		else
		{
			flag = 0;
			break;
		}
	}	
	return flag;
}
int IsUpper(const char *str)	//判断内容是否全是大写字母 1-是 0-不是
{
	int flag = 0;
	for(str; *str != '\0'; str++)
	{
		if(*str >= 65 && *str <= 90)
		{
			flag = 1;
			continue;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int IsLower(const char *str)	//判断字符是否全是小写字母 1-是 0-不是
{
	int flag = 0;
	for(str; *str != '\0'; str++)
	{
		if(*str >= 97 && *str <= 122)
		{
			flag = 1;
			continue;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
} 
int IsASCLL(const char *str) //判断是否全是ASCLL字符 1-是 0-不是
{
	int flag = 0;
	for(str; *str != '\0'; str++)
	{
		if(*str >= 0 && *str <= 127)
		{
			flag = 1;
			continue;
		}
		else
		{
			flag = 0;
			break; 
		} 
	}	
	return flag;
}
// 暴力算法 -- BF
char* STRSTR(const char* str1, const char* str2)
{
		char* s1 = (char*) str1;
		char* s2 = (char*) str2;
		char* current = (char*) str1;

		while(*current)
		{
			s1 = current;
			s2 = (char*)str2;

			while((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
			{
				s1++;	s2++;
			}

			if(*s2 == '\0')
				return current;

			if(*s1 == '\0')
				return NULL;
			current++;
		}
		return NULL;	
}

/*****************XML  解析*************************/
int GetXMLBuffer_Str(const char* in_XMLBuffer, const char* in_FieldName, char* out_Value)
{
	if(out_Value == 0) return 0;	// 要存的地址不存在，即out_Value指针是空指针
	char* start = 0;
	char* end = 0;
	char startStr[50];
	char endStr[50];
	
	int len_Field = STRLEN(in_FieldName);
	MEMSET(startStr, 0, sizeof(startStr));
	MEMSET(endStr	 , 0, sizeof(endStr));
	STRCPY(startStr, "<");
	STRCAT(startStr, in_FieldName);
	STRCAT(startStr, ">");
	STRCPY(endStr, "</");
	STRCAT(endStr, in_FieldName);
	STRCAT(endStr, ">");

	MEMSET(start, 0, sizeof(start));
	MEMSET(end, 0, sizeof(end));
	start = (char*)STRSTR(in_XMLBuffer, startStr);
	if(start != 0)
		end	= (char*)STRSTR(in_XMLBuffer, endStr);

	if((start == 0) || (end == 0))
		return 0;		//未找到匹配字符串
	int length_Str = STRLEN(start) - STRLEN(end) - 2 - len_Field;
	STRNCPY(out_Value, start+2+len_Field, length_Str);

	return 1;
}

int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value)
{
	GetXMLBuffer_Str(in_XMLBuffer, in_FieldName, (char*) out_Value);
	
	*out_Value = ATOI((const char*)out_Value);
	
	return 1;
}

int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value)
{
	GetXMLBuffer_Str(in_XMLBuffer, in_FieldName, (char*) out_Value);
	
	*out_Value = ATOD((const char*)out_Value);

	return 1;
}

/*********************************时间函数***************************************/
/**
 * 把整数的时间转换为字符串格式的时间，
 * 格式如："2019-02-08 12:05:08"，
 * 如果转换成功函数返回1，失败返回0
 * */
int TIMETOSTR(const time_t ti,char *strtime)
{
	struct tm* ptimer;	//C内置时间结构体
	ptimer = localtime(&ti);
	
	MEMSET(strtime, 0, sizeof(strtime));

	sprintf(strtime,"%d-%d-%d %d:%d:%d", \
							ptimer->tm_year+1900, \
							ptimer->tm_mon+1, \
							ptimer->tm_mday, \
							ptimer->tm_hour, \
							ptimer->tm_min, \
							ptimer->tm_sec );
	return 1;
}

/**
 * 字符串格式的时间转换为整数的时间
 * 写的很烂
 * */
int STRTOTIME(const char *strtime,time_t *ti)
{
	char* str = (char*) strtime;
	char syear[10], smon[3], sday[3], shour[3], smin[3], ssec[3];

	MEMSET(syear, 0, sizeof(syear));
	MEMSET(smon, 0, sizeof(smon));
	MEMSET(sday, 0, sizeof(sday));
	MEMSET(shour, 0, sizeof(shour));
	MEMSET(smin, 0, sizeof(smin));
	MEMSET(ssec, 0, sizeof(ssec));
	
	size_t len, index = 0;
	len = STRLEN(strtime);
	int i,j;
	
	for(i = index,j = 0; i < len; i++, j++)
	{	
		syear[j] = strtime[i];
		if(strtime[i] == '-')
		{
			syear[j] = '\0';
		  index = i+1;
			break;
		}
  }

	for(i = index,j = 0; i < len; i++, j++)
	{	
		smon[j] = strtime[i];
		if(strtime[i] == '-')
		{
			smon[j] = '\0';
		  index = i+1;
			break;
		}
  }

	for(i = index,j = 0; i < len; i++, j++)
	{	
		sday[j] = strtime[i];
		if(strtime[i] == ' ')
		{
			sday[j] = '\0';
		  index = i+1;
			break;
		}
  }

	for(i = index,j = 0; i < len; i++, j++)
	{	
		shour[j] = strtime[i];
		if(strtime[i] == ':')
		{
			shour[j] = '\0';
		  index = i+1;
			break;
		}
  }

	for(i = index,j = 0; i < len; i++, j++)
	{	
		smin[j] = strtime[i];
		if(strtime[i] == ':')
		{
			smin[j] = '\0';
		  index = i+1;
			break;
		}
  }

	for(i = index,j = 0; i < len; i++, j++)
		ssec[j] = strtime[i];
 	

	struct tm timer;
	MEMSET((char*)&timer, 0, sizeof(timer));
	timer.tm_year = ATOI(syear) - 1900;
	timer.tm_mon = ATOI(smon) - 1;
	timer.tm_mday = ATOI(sday);
	timer.tm_hour = ATOI(shour);
	timer.tm_min = ATOI(smin);
	timer.tm_sec = ATOI(ssec);	
	*ti = mktime(&timer);
}

/**
 *
 *  获取操作系统当前的时间
 *
 * */
void LOCALTIME(char *out_stime,const char *in_fmt,const int in_interval)
{
	time_t timep;
	
	struct tm* ptimer;	//C内置时间结构体
	timep = time(&timep) + 1000 * in_interval;
	ptimer = localtime(&(timep));

	if(STRCMP(in_fmt, "yyyy-mm-dd hh24:mi:ss") == 0)
		sprintf(out_stime,"%d-%d-%d %d:%d:%d", \
							ptimer->tm_year+1900, \
							ptimer->tm_mon+1, \
							ptimer->tm_mday, \
							ptimer->tm_hour, \
							ptimer->tm_min, \
							ptimer->tm_sec );
	else if(STRCMP(in_fmt, "yyyymmddhh24miss") == 0)
		sprintf(out_stime,"%d%d%d%d%d%d", \
							ptimer->tm_year+1900, \
							ptimer->tm_mon+1, \
							ptimer->tm_mday, \
							ptimer->tm_hour, \
							ptimer->tm_min, \
							ptimer->tm_sec );
	else if(STRCMP(in_fmt, "yyyy-mm-dd") == 0)
		sprintf(out_stime,"%d-%d-%d", \
							ptimer->tm_year+1900, \
							ptimer->tm_mon+1, \
							ptimer->tm_mday );
	
	else if(STRCMP(in_fmt, "yyyymmdd") == 0)
		sprintf(out_stime,"%d%d%d", \
							ptimer->tm_year+1900, \
							ptimer->tm_mon+1, \
							ptimer->tm_mday );
	
	else if(STRCMP(in_fmt, "hh24:mi:ss") == 0)
		sprintf(out_stime,"%d:%d:%d", \
							ptimer->tm_hour, \
							ptimer->tm_min, \
							ptimer->tm_sec );
	
	else if(STRCMP(in_fmt, "hh24miss") == 0)
		sprintf(out_stime,"%d%d%d", \
							ptimer->tm_hour, \
							ptimer->tm_min, \
							ptimer->tm_sec );
	
	else if(STRCMP(in_fmt, "hh24:mi") == 0)
		sprintf(out_stime,"%d:%d", \
							ptimer->tm_hour, \
							ptimer->tm_min );

	else if(STRCMP(in_fmt, "hh24") == 0)
		sprintf(out_stime,"%d", \
							ptimer->tm_hour );
	
	else if(STRCMP(in_fmt, "mi") == 0)
		sprintf(out_stime,"%d", 
							ptimer->tm_sec );
}	

```

_pub : 封装的函数

``` .
1.	ABS, LABS -- 绝对值
2.	CTOI -- 字符转数字
3.	POW -- 求幂值
4.	STRLEN -- 求字符串长度  ××× 已删除合并到8
5.	ATOI, ATOL -- 字符串转数字
6.	ISALPHA, ISALNUM, ISDIGIT, ISLOWER, ISUPPER, TOLOWER, TOUPPER -- 字符操作的一系列函数
7.	FABS, ROUND, CEIL, FLOOR, MODF -- 浮点数一系列函数
8.	STRLEN, STRCPY, STRNCPY, STRCAT, STRNCAT, STRCHR, STRRCHR -- 字符串一系列函数
9.  STRCMP, STRNCMP -- 字符串比较函数
10. ToUpper, ToLower, IsDigit, IsUpper, IsLower, IsASCLL -- 字符串判断函数
11. STRSTR -- BF匹配子字符串
12.	GetXMLBuffer_Str, GetXMLBuffer_Int, GetXMLBuffer_Double
13. 补充了修补了ATOI, ATOL, ATOD(不精确), ISSPACE 等函数
14. TIMETOSTR, STRTOTIMR, LOCALTIME -- 时间操作函数
```

测试代码：test.c

```c
#include "_pub.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

struct st_girl
{
	char name[51];
	int age;
	int height;
	double weight;
	char stature[31];
	char facevalue[31];
};


int main()
{
#if 0
	long int in,out;
	printf("请输入要求值的数字\n");
	scanf("%ld",&in);
	if(sizeof(in) <= sizeof(int))
		out = ABS(in);
	else
		out = LABS(in);
	printf("out = %ld\n",out);
#endif
#if 0	
	char a;
	printf("输入要转化的字符数字\n");
	scanf("%c",&a);
	int bb = CTOI(a);
	printf("out = %d\n",bb);
#endif
#if 0
	printf("5^5 = %lld\n",POW(5,5));
	printf("2^33 = %lld\n",POW(2,33));
#endif
#if 0
	char aa[30];
	scanf("%s",aa);
	printf("len of aa = %d\n",STRLEN(aa));
	//printf("aa = %d\n",ATOI(aa));
	printf("aa = %ld\n",ATOL(aa));
#endif
#if 0
	char a = 'a',B = 'B';
	int c = '5',e = '6';
	char d = '\\';
	printf("%d %d %d %d %d %c %c\n",ISALPHA(a),ISDIGIT(c),ISDIGIT(e),ISUPPER(B),ISALNUM(d),TOLOWER(B),TOUPPER(a));
#endif
#if 0
	double i = -64.54864;
	double j = FABS(i);
	printf("i=%.5lf,j=%.5lf\n", i,j);
	double k = 6.7,b = 3.3;
	printf("%lf\n",ROUND(k));
	printf("%lf\n",ROUND(b));
	printf("%lf,%lf\n",CEIL(1.3),FLOOR(1.3));
	double z = 1.3;
	double *pz = &z; 
	printf("%lf\n",MODF(z,pz));
	printf("%lf\n",*pz);
#endif
#if 0
	char str[21];
	scanf("%s",str);
	printf("%lu\n",strlen1(str));	
	char str1[50],str2[30];
	memset1(str1, 0, sizeof(str1));
	memset1(str2, 0, sizeof(str2));
	strcpy1(str1, "10000");
	printf("str1=%s=\n", str1);
	strcpy1(str2, "1008611");
	printf("str2=%s=\n", str2);
	strcpy1(str1, str2);
	printf("str1=%s=\n",str1);
	printf("----------------------\n");
	strcpy(str1,str2);
	printf("str1=%s=\n",str1);
#endif
#if 0
	char A[30],B[10];
  //置空很重要
	memset1(A, 0,sizeof(A));
	memset1(B, 0,sizeof(B));
	printf("A=%s=,B=%s=\n",A,B);
	strcpy1(A, "Hello");
	strcpy1(B, "World");
	printf("A=%s=,B=%s=\n",A,B);
	strncpy1(A, "你 好",7);
	strncpy1(B, "世 界",7);
	strcat1(A,B);
	strncat1(A, B, 7);
	printf("A=%s=,B=%s=\n",A,B);
#endif
#if 0
	char X[20];
	char c = 'b';
	MEMSET(X, 0, sizeof(X));
	STRCPY(X, "ksdkkbdeefb"); 
	printf("%s\n",STRCHR(X, '1'));
	printf("-----------------\n%s\n",STRCHR(X, '1'));
	printf("%s\n--------------------", strrchr(X, 's'));
	printf("\n%s\n",STRRCHR(X, 's'));
#endif
#if 0
	char str1[15],str2[10];
	MEMSET(str1, 0, sizeof(str1));
	MEMSET(str2, 0, sizeof(str2));
	STRCPY(str1, "ABCdd");
	STRCPY(str2, "ABCddee");
	printf("str1?str2=.%d.\n",strcmp(str1, str2));
	printf("str1?str2=.%d.\n",STRCMP(str1, str2));
	printf("str1?str2=.%d.\n",STRNCMP(str1, str2, 2));
	printf("str1?str2=.%d.\n",STRNCMP(str1, str2, 2));
	ToUpper(str2);
	printf("=%s=\n",str2);
	printf("%d,%d,%d,%d\n", IsUpper(str2),IsDigit(str2),IsLower(str2),IsASCLL(str2));
	printf("%d,\n",IsDigit(str2));
	printf("==================\n");
	ToLower(str2);	
	printf("%d,%d,%d,%d\n", IsUpper(str2),IsDigit(str2),IsLower(str2),IsASCLL(str2));
	printf("%d\n",IsDigit("1123545998877445566332211"));
#endif
#if 0
	printf("%s\n",strstr("111222333","222"));
	printf("%s\n",STRSTR("111222333","222"));
	printf("%s\n",strstr("111222333","333"));
	printf("%s\n",STRSTR("111222333","333"));
	printf("%s\n",strstr("11122233e3","eeee"));
	printf("%s\n",STRSTR("11122233e3","eeee"));
#endif

#if 0
/*测试XML*/
struct st_girl beautygirl;
	struct st_girl*  beauty = &beautygirl;
	strcpy(beauty->name, "西施");
	beauty->age = 18;
	beauty->height = 168;
	beauty->weight = 48.5;
	strcpy(beauty->stature, "火辣");
	strcpy(beauty->facevalue, "漂亮");
	char str[255];
	memset(str, 0, sizeof(str));
	sprintf(str,"<name>%s</name>"							\
						 	"<age>%d</age>"								\
						 	"<height>%d</height>"					\
							"<weight>%lf</weight>"				\
							"<stature>%s</stature>"				\
							"<facevalue>%s</facevalue>"	,	
							(*beauty).name, 
							(*beauty).age, 
							(*beauty).height, 
							(*beauty).weight, 
							(*beauty).stature, 
							(*beauty).facevalue);
	char str1[50];
	MEMSET(str1, 0, sizeof(str1));
	GetXMLBuffer_Str(str, "name", str1);
	printf("=%s=\n", str1);
	MEMSET(str1, 0, sizeof(str1));
	GetXMLBuffer_Str(str, "stature", str1);
	printf("=%s=\n", str1);
	MEMSET(str1, 0, sizeof(str1));
	GetXMLBuffer_Str(str, "facevalue", str1);
	printf("=%s=\n", str1);

	printf("%s\n", str);
	int age,height;
	double dd;
	GetXMLBuffer_Int(str, "age", &age);
	GetXMLBuffer_Int(str, "height", &height);	
	GetXMLBuffer_Double(str, "weight", &dd);	
	printf("=age=%d,height=%d=,weight=%lf\n", age, height, dd);
#endif

#if 0	
	time_t t;
	char str[120];
	MEMSET(str, 0, sizeof(str));
	t = time(NULL);
	printf("%ld\n", t);	
	TIMETOSTR(t, str);
	printf("datetime=%s\n", str);
	STRTOTIME(str,&t);
	printf("t=%ld\n", t);
	char str1[30];
	MEMSET(str1, 0, sizeof(str1));
#endif

	char out_time[30];
	MEMSET(out_time, 0, sizeof(out_time));
	LOCALTIME(out_time, "yyyy-mm-dd hh24:mi:ss", 0);
	printf("out_time=%s\n", out_time);
	LOCALTIME(out_time, "yyyymmddhh24miss", 0);
	printf("out_time=%s\n", out_time);
	LOCALTIME(out_time, "yyyy-mm-dd", 0);
	printf("out_time=%s\n", out_time);
	LOCALTIME(out_time, "yyyymmdd", 0);
	printf("out_time=%s\n", out_time);
	LOCALTIME(out_time, "hh24:mi:ss", 0);
	printf("out_time=%s\n", out_time);
	return 0;
}
```

