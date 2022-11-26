#include <iostream>
#include "Shapes.h"
using namespace std;
int main(void){
    Point p = Point(0, 0);
    Square sq = Square(p, 5);
    //sq.Draw('#');
    RightTriangle rt = RightTriangle(p, 5);
    rt.Draw('#');
}
//{
//    int choice;
//    int x,y,radius, width,length;
//    bool fQuit = false;
//    Shape * sp;
//    while ( !fQuit )
//    {
//        cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
//        cin >> choice;
//        switch (choice)
//        {
//            case 0: fQuit = true;
//                break;
//            case 1:
//                cout<<"Base Point: ";
//                cin>>x>>y;
//                cout<<"Radius: ";
//                cin>>radius;
//                sp = new Circle(Point(x,y),radius);
//                break;
//            case 2:
//                cout<<"Base Point: ";
//                cin>>x>>y;
//                cout<<"Width: ";
//                cin >> width;
//                cout<<"Length: ";
//                cin >> length;
//                sp = new Rectangle(Point(x,y),width,length);
//                break;
//            case 3:
//                cout<<"Base Point: ";
//                cin>>x>>y;
//                cout<<"Width: ";
//                cin >> width;
//                sp = new Square(Point(x,y),width);
//                break;
//            default:
//                cout<<"Please enter a number within 0-3"<<endl;
//                continue;
//                break;
//        } // end of switch statement
//
//        if( !fQuit )
//        {
//            sp->Print();
//            sp->Draw();
//        }
//        delete sp;
//        sp = 0;
//        cout << "\n";
//    } // end of while statement
//    return 0;
//}
