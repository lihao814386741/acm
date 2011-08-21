#include <stdio.h>
#include <string.h>

#define N 200010
char s[N];
int n, sa[N], height[N], rank[N], tmp[N], top[N];

void makesa(){
// O(N * log N)
int i, j, len, na;
na = (n < 256 ? 256 : n);
memset(top, 0, na * sizeof(int));
for (i = 0; i < n ; i++) top[ rank[i] = s[i] & 0xff ]++;
for (i = 1; i < na; i++) top[i] += top[i - 1];
for (i = 0; i < n ; i++) sa[ --top[ rank[i] ] ] = i;
for (len = 1; len < n; len <<= 1) {
for (i = 0; i < n; i++) {
j = sa[i] - len; if (j < 0) j += n;
tmp[ top[ rank[j] ]++ ] = j;
}
sa[ tmp[ top[0] = 0 ] ] = j = 0;
for (i = 1; i < n; i++) {
if (rank[ tmp[i] ] != rank[ tmp[i-1] ] ||
rank[ tmp[i]+len ]!=rank[ tmp[i-1]+len ])
top[++j] = i;
sa[ tmp[i] ] = j;
}
memcpy(rank, sa , n * sizeof(int));
memcpy(sa , tmp, n * sizeof(int));
if (j >= n - 1) break;
}
}
void makesa1()
{
	int na = (n < 256 ? 256 : n);
	int j, i, len;
	memset(top, 0, na * sizeof (int));
	for ( i = 0; i < n; i ++) top[rank[i] = s[i] & 0xff] ++;
	for ( i = 1; i < na; i ++) top[i] += top[i - 1];
	for ( i = 0; i < n; i ++) sa[--top[rank[i]]] = i;

	for ( len = 1; len < n; len <<= 1)
	{
		for ( i = 0; i < n; i ++)
		{
			j = sa[i] - len;
			if (j < 0) j += n;
			tmp[top[rank[j]] ++ ] = j;
		}

		sa[tmp[top[0] = 0]] = j = 0;
		for ( i = 1; i < n; i++)
		{
			if (rank[tmp[i]] != rank[tmp[i - 1]] || rank[tmp[i] + len] != rank[tmp[i - 1] + len]) top[++j] = i;
			sa[tmp[i]] = j;
		}
		
		memcpy(rank, sa, n * sizeof (int));
		memcpy(sa, tmp, n * sizeof (int));

		if (j >= n - 1) break;
	}
}
void lcp(){
// O(4 * N)
	int len = strlen(s),i,j,k = 0;
		for (i = 0; i < len; i++) rank[sa[i]] = i;
			for (i = 0; i < len-1; height[rank[i++]] = k)
					for (k?k--:0,j = sa[rank[i] - 1]; s[i+k] == s[j+k]; k++) ;
									return;
}
int main()
{
	char temp1[N], temp2[N];
	scanf("%s %s", temp1, temp2);
	int limit = strlen(temp1);
	strcpy(s, temp1);
	strcat(s, "$");
	strcat(s, temp2);
	n = strlen(s);
	int max = 0;
	makesa();
	lcp();
	for (int i = 1; i < n; i ++)
	{
		if ((sa[i - 1] + height[i] <= limit && sa[i] > limit) || (sa[i] + height[i] <= limit && sa[i - 1] > limit))
		{
			if (height[i] > max)
			{
				max = height[i];
			}
		}
	}


	printf("%d\n", max);



}
