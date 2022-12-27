#include "spider.h"


int main()
{
    cout << "*************************************************************" << endl;
    cout << "\t\t欢迎使用人工智能网络爬虫系统" << endl;
    cout << "*************************************************************" << endl;
    cout << "请输入要抓取的网页链接:"       << endl;

    //创建文件夹 (L:告诉编译器，字符编码使用unicode编码)
    //CreateDirectory(L"image", NULL);  //出错
    CreateDirectory("image", NULL);

    //输入一个URL
    string starturl;
    (cin >> starturl).get();

    //开始抓取
    Start(starturl);

    return 0;
}

/**< 开始抓取 */
bool Start(string url)
{
    queue<string> q;
    //插入一条URL
    q.push(url);

    //循环不停地从队列中取出URL
    while(!q.empty())
    {
        string currenturl = q.front();  //取出一条
        q.pop();    //删除取出的那条URL

        //解析（分割字符串）


    }
}
