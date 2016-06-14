#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
enum grade_mode{level,num};
union grade
{
    char level;
    double num;
};
struct course
{
    char c_num[10],c_name[20];
    grade g;
};
struct student
{
    char s_num[10],s_name[20],sex;
    course c;
    grade_mode g_mode;
    double score;
};
void input_course(course *c)
{
    cin>>c->c_num>>c->c_name;
}
void input_student(student *s[],int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>s[i]->s_num>>s[i]->s_name;
        char sex[5];
        cin>>sex;
        if (strcmp(sex,"m")==0||strcmp(sex,"男")==0)
            s[i]->sex='m';
        else
            s[i]->sex='f';
        input_course(&s[i]->c);
        cin>>s[i]->score;
    }
}
int main()
{
    cout<<setw(12)<<"请输入"<<endl;
    cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"课程号"<<setw(10)<<"课程名"<<setw(10)<<"分数"<<endl;

    return 0;
}
