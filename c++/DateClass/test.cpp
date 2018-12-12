#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    Date a1( 2018, 12, 26);
    Date a2( 2019, 1, 1);
    Date a3( a1);
    const Date a4( a3);
    cout << a4;
    cout << a1.getYear() << a1.getMonth()<<a1.getDay()<<endl;
  /*  cout<<a4<<endl;
    cout<< "a1 = "<< a1<< "   "<< "a2 = "<< a2<< "   "<< "a3 = "<< a3<< endl;
    cout<< "a1 += 100 = "<< ( a1 += 100)<< "   "
        << "a2 += 365 = "<< ( a2 += 365)<< "   "
        << "a3 += 700 = "<< ( a3 += 700)<< endl;
    cout<< "a1 -= 100 = "<< ( a1 -= 100)<< "   "
        << "a2 -= 365 = "<< ( a2 -= 365)<< "   "
        << "a3 -= 700 = "<< ( a3 -= 700)<< endl;
    cout<< "a1++ = "<< a1++<< "   "
        << "a2++ = "<< a2++<< "   "
        << "a3++ = "<< a3++<< endl;
    cout<< "a1-- = "<< a1--<< "   "
        << "a2-- = "<< a2--<< "   "
        << "a3-- = "<< a3--<< endl;
    cout<< "++a1 = "<< ++a1<< "   "
        << "++a2 = "<< ++a2<< "   "
        << "++a3 = "<< ++a3<< endl;
    cout<< "--a1 = "<< --a1<< "   "
        << "--a2 = "<< --a2<< "   "
        << "--a3 = "<< --a3<< endl;
    cout<< "a1 - a2 = "<< ( a1 - a2)<< endl;
    cout<< "a1 > a2 ? "<< ( a1 > a2)<< endl;
    cout<< "a1 >= a2 ? "<< ( a1 >= a2)<< endl;
    cout<< "a1 < a2 ? "<< ( a1 < a2)<< endl;
    cout<< "a1 <= a2 ? "<< ( a1 <= a2)<< endl;
    cout<< "a2 == a3 ? "<< ( a2 == a3)<< endl;
    cout<< "a2 1= a3 ? "<< ( a2 != a3)<< endl;
   */
    return 0;
}
