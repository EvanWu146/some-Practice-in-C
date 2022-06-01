#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector> 
using namespace std; 
const int MAX = 60;
const double eps = 1e-8;
struct point{    
double x, y;
};
int N, M;
double left, right, mid;
double T1, T2, V;
point laser[MAX];
point enemy[MAX];
int from[MAX][MAX];
bool used[MAX][MAX];
double t[MAX][MAX];
vector<double> G[MAX]; 
int dcmp(double f){    
   if(fabs(f) < eps) return 0;
   if(f > 0) return 1;    
   return -1;
   } 
double dist(point &a, point &b){    
   return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
   } 
bool match(int i){
    for (int j = 1; j <= N; ++j){        
	if (dcmp(t[i][j] - mid) > 0) continue;       
	for (int k = 0, sz = G[j].size(); k < sz; ++k){            
	if (dcmp(t[i][j] + G[j][k] - mid) > 0) break;            
	if (used[j][k]) continue;            
	used[j][k] = true;            
	if (from[j][k] == -1 || match(from[j][k])){                
	from[j][k] = i;                
	return true;            
	}        
	}    
	}    
	return false;
	} int Hungary(){    
	int tot = 0;    
	memset(from, -1, sizeof(from));    
	for (int i = 1; i <= M; ++i){       
	memset(used, false, sizeof(used));        
	if (match(i)) ++tot;    
	}    
	return tot;}  
	int main(void){    
	freopen("input.txt", "r", stdin);    
	while (scanf("%d %d %lf %lf %lf", &N, &M, &T1, &T2, &V) != EOF){        
	for (int i = 1; i <= M; ++i)            
	scanf("%lf %lf", &enemy[i].x, &enemy[i].y);        
	for (int i = 1; i <= N; ++i)            
	scanf("%lf %lf", &laser[i].x, &laser[i].y);        
	for (int i = 1; i <= M; ++i)            
	for (int j = 1; j <= N; ++j)                
	t[i][j] = dist(enemy[i], laser[j]) / V;        
	T1 /= 60.0;        
	for (int i = 1; i <= N; ++i){            
	G[i].clear();            
	double cnt = T1;            
	for (int j = 1; j <= M; ++j, cnt += T2 + T1)                
	G[i].push_back(cnt);        
	}        
	left = 0.0, right = 0x3f3f3f3f;        
	while (dcmp(right - left) != 0){            
	mid = (right + left) / 2.0;            
	int k = Hungary();            
	printf("%f\n", mid);            
	if (k == M) right = mid;            
	else left = mid;        
	}       
	printf("%f\n", right);    
	}    
	return 0;
	}

