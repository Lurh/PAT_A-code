#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
struct stu  //ѧ���ṹ  
{  
    int id; //id  
    int s[5];   //����������ڲ���0��ʼ���  
    int score;  //�ܷ�  
    int pass;   //��ȫ��ȷ��Ŀ��  
    int ns; //���ύ�����κ�ͨ�������־��0����û��ͨ��  
    stu()   //��ʼ��  
    {  
        id=0;score=0;pass=0;ns=0;  
        for(int i=0;i<5;i++)  
            s[i]=-2;    //�������Ҫ�󣬶�û�д��������-2��ʾ  
    }  
};  
  
bool cm(const stu &s1,const stu &s2);   //�Ƚ�  
  
int main()  
{  
    int n,k,m;  
    cin>>n>>k>>m;  
  
    stu *student=new stu [n];   //ѧ�������i��Ӧ��ʵid-1  
    int p[5];   //���ŷ���  
      
    int i,j;  
    for(i=0;i<k;i++) //������Ϣ  
        scanf("%d",&p[i]);  
    int id,p_id,ps;  
    for(i=0;i<m;i++)  
    {  
        scanf("%d %d %d",&id,&p_id,&ps);  
        if(ps>student[id-1].s[p_id-1])  
            student[id-1].s[p_id-1]=ps;  
    }  
  
    for(i=0;i<n;i++) //�����ܷ֣���ȫ��ȷ��Ŀ�����Ƿ���Ҫ�޳�  
    {  
        student[i].id=i+1;  
        for(j=0;j<k;j++)  
        {  
            if(student[i].s[j]>=0)  
            {  
                student[i].score+=student[i].s[j];  
                student[i].ns=1;  
            }  
            if(student[i].s[j]==p[j])  
                student[i].pass++;  
        }  
    }  
    stable_sort(student,student+n,cm); //�ȶ����򣬿�����ȥһ��id�Ƚ�  
  
    int rank=1; //��ǰ�����Σ���������  
    int score=student[0].score; //��ǰ�ķ���  
    for(i=0;i<n;i++)  
    {  
        if(student[i].ns==0)    //�����������ݶ�����  
            break;  
        if(student[i].score!=score) //���ǲ��У�ˢ�·���  
        {  
            rank=i+1;  
            score=student[i].score;  
        }  
        printf("%d %05d %d",rank,student[i].id,student[i].score);   //�����Ϣ  
        for(j=0;j<k;j++)  
        {  
            if(student[i].s[j]>=0)  
                printf(" %d",student[i].s[j]);  
            else if(student[i].s[j]==-1)  
                printf(" 0");  
            else  
                printf(" -");  
        }  
        printf("\n");  
    }  
  
    delete [] student;  
  
    return 0;  
}  
  
bool cm(const stu &s1,const stu &s2)    //���ֺܷ���ȫ��ȷ��Ŀ�������ñȽ�  
{  
    if(s1.score>s2.score)  
        return true;  
    else if(s1.score==s2.score)  
        return s1.pass>s2.pass;  
    else  
        return false;  
}  
