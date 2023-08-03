/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                       MULTIPLE INHERITANCE
*******************************************************************************/


#include<iostream>
using namespace std;


class Shape     // First base class Shape- Have info of diferent shapes and functions to get the dimentions
{
        protected:
                float height,radius,len,br ;          
        public:
            
            Shape(){
                cout << "\n\nCalling First base class Shape\n";
            }   
            void Enter_height(void)
            {
                cout << "\n\t Enter the height  : ";  cin >> height;
            }
            void Enter_radius(void)
            {
                cout << "\n\t Enter the radius: ";  cin >> radius ;
            }
            void Enter_length(void)
            {
                cout << "\n\t Enter the length : ";  cin >> len;
            }
            void Enter_breadth(void)
            {
                cout << "\n\t Enter the breadth : ";  cin >> br;
            }
            void Info_circle(void)
            {
                cout <<"\nCircle is a 2-D figure with dimension radius.\n" <<endl;
            }
            void Info_cuboid(void)
            {
                cout <<"\n\tCuboid is a 3-D figure with dimensions height, length and breadth.\n" <<endl;
            }
            void Info_rectangle(void)
            {
                cout <<"\tRectangle is a 2-D figure with dimensions length and breadth.\n" <<endl;
            }
               
};

class Rectangle    //Second base class Rectangle-takes value of length, breadth and calculates Area
{
                protected:
                        float length, breadth ;
                public:
                
                Rectangle(){
                    cout<<"Calling second base class Rectangle\n";
                }
                void Enter_lb(void)
                {
                    cout << "\t Enter the length  : "; 
                    cin >> length ;
                    cout << "\t Enter the breadth : " ;
                    cin >> breadth ;
                }
                
                void Display_ar(void)
                {
                    cout << "\t Area of the rectangle = " << (length * breadth)<<"\n";
                }
};


class Cuboid : public Shape, public Rectangle // Derived class cuboid, inherited from classes Shape & Rectangle
{                                               
                public:
                
                Cuboid(){
                    cout<<"Calling Derived class cuboid\n";
                }
                void SurfaceArea_Cuboid(void)
                {
                    cout << "\t The surface area of cuboid : "<< (2*height*length+2*length*breadth+2*height*breadth)<<"\n";
                }
                void volume_cy(void)
                    {
                    cout << "\t The volume of the cuboid   : "<< (height*length*breadth) ;
                    } 
};


int main()
{   
   
    
    
    cout<<"\n-------------------------------------------------------------------------------";
    cout << "\n\t\t\t\tMULTIPLE INHERITANCE";
    Shape c ;
    c.Info_rectangle();
    Rectangle rect ;
    rect.Enter_lb( );
    rect.Display_ar( );
    
    cout<<"\n-------------------------------------------------------------------------------";
    
    c.Info_cuboid( );
    
    cout<<"\n-------------------------------------------------------------------------------";

    /* Object Cbd of the class cuboid can access all the public
     members of the class circle as well as of the class rectangle*/
    Cuboid Cbd ;
    Cbd.Enter_height( );
    Cbd.Enter_lb( );
    Cbd.SurfaceArea_Cuboid();
    Cbd.volume_cy( );
return 0;
}