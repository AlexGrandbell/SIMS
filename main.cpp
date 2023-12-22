#include "menu.h"

int main() {
    cout << "\n欢迎进入学生信息管理系统(顺序存储版)" << endl;
    cout<<"你可以随时输入'q'来退出当前操作。"<<endl;
    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    string input;

    //不断循环，执行操作
    do {
        //界面与输入
        outPutMenu();//界面
        fflush(stdin);//清除输入流缓存
        nSelection = -1;
        try {
            nSelection = inputInt();

            //根据输入选择行为
            switch (nSelection) {
                case 0: {
                    ExitApp();
                    return 0;
                }//再见
                case 1: {
                    ShowAll();
                    break;
                }//显式
                case 2: {
                    Add();
                    break;
                }//插入
                case 3: {
                    Find();
                    break;
                }//查找
                case 4: {
                    Delete();
                    break;
                }//删除
                case 5: {
                    Refresh();
                    break;
                }//更新
                case 6: {
                    Length();
                    break;
                }//统计
                case 7: {
                    Sorts();
                    break;
                }//排序
                case 8: {
                    Clear();
                    break;
                }//清空
                default: {
                    printf("您输入的菜单序号错误,");
                    break;
                }//错误
            }//完成
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
        if (nSelection != 0) {
            printf("继续操作请按1，关闭程序请按0:");
            fflush(stdin);//清除输入流缓存
            nSelection = -1;
            try {
                nSelection = inputInt();
                if (nSelection == 0) {
                    ExitApp();
                }
            }catch  (const exception& e){
                cerr<<e.what()<<endl;
            }
        }
    } while (nSelection != 0);
    return 0;
}
