// Iram Abid
//20COB051
//SERIAL NO-06
import java.util.Scanner;

class Polygon{
    int numberOfSides;
    Polygon(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of sides : ");
        numberOfSides = sc.nextInt();
        short ch;
        try{
                if(numberOfSides<0){
                    throw new Exception("Negative values are not allowed");
                }
                if(numberOfSides==3){
                    System.out.println("Enter:\n1)to enter length of one side and perpendicular length to corresponding side \n2)To enter side length of Triangle");
                    ch = sc.nextShort();
                    switch (ch){
                        case 1:
                            System.out.println("Enter length of base and height");
                            double a = sc.nextDouble();
                            double b = sc.nextDouble();
                            try{
                                if (a<0||b<0){
                                    throw new Exception("Negative values are not allowed");
                                }
                                System.out.println("Area of Triangle is : "+Area(a,b));
                            }catch (Exception e){
                                System.out.println(e);
                            }
                            break;
                        case 2:
                            System.out.println("Enter side length of Triangle");
                            double c = sc.nextDouble();
                            double d = sc.nextDouble();
                            double e = sc.nextDouble();
                            try{
                                if (c<0||d<0||e<0){
                                    throw new Exception("Negative values are not allowed");
                                }
                                System.out.println("Area of Triangle is : "+Area(c,d,e));
                                System.out.println("Perimeter of Triangle is : "+Perimeter(c,d,e));
                            }catch (Exception ex){
                                System.out.println(ex);
                            }
                            break;
                        default:
                            System.out.println("Invalid choice entered.");
                    }
                }
                else if(numberOfSides==4){
                    System.out.println("Enter:\n1)to enter length of both Diagonals of Rhombus\n2)To enter side length of Rectangle");
                    ch = sc.nextShort();
                    switch (ch){
                        case 1:
                            System.out.println("Enter Diagonal length of Rhombus");
                            double a = sc.nextDouble();
                            float b = sc.nextFloat();
                            try{
                                if (a<0||b<0){
                                    throw new Exception("Negative values are not allowed");
                                }
                                System.out.println("Area of Rhombus is : "+Area(a,b));
                            }catch (Exception e){
                                System.out.println(e);
                            }
                            break;
                        case 2:
                            System.out.println("Enter Side length of rectangle");
                            float c = sc.nextFloat();
                            float d = sc.nextFloat();
                            try{
                                if (c<0||d<0){
                                    throw new Exception("Negative values are not allowed");
                                }
                                System.out.println("Area of Rectangle is : "+Area(c,d));
                                System.out.println("Perimeter of Triangle is : "+Perimeter((double)c,(double)d,(double)c,(double)d));
                            }catch (Exception e){
                                System.out.println(e);
                            }
                            break;
                        default:
                            System.out.println("Invalid choice entered.");
                    }
                }
                else if(numberOfSides==5){
                    System.out.println("Enter Length of apothem and side length ");
                    float apothem = sc.nextFloat();
                    double sideLength = sc.nextDouble();
                    try{
                        if (apothem<0||sideLength<0){
                            throw new Exception("Negative values are not allowed");
                        }
                        System.out.println("Area of Pentagon is : "+Area(apothem,sideLength));
                    }catch (Exception e){
                        System.out.println(e);
                    }
                }
                else{
                    System.out.println("Unexpected Parameters");
                }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    public Double Perimeter(Double ... a){
        Double p=0d;
        for(Double x:a){
            p += x;
        }
        return p;
    }
    public Double Area(Double base , Double height){
        return (base*height)/2;//area of triangle
    }
    public Double Area(Double a,Double b,Double c){
        double s = (a+b+c)/2;//semiPerimeter
        return Math.sqrt((s)*(s-a)*(s-b)*(s-c));
    }
    public Float Area(Float a,Float b){
        return a*b;//area of rectangle
    }
    public Double Area(Float a,Double b){
        return (a*b*5)/2;//area of pentagon
    }
    public Float Area(Double a,Float b){
        return (float) ((a*b)/2);//area of rhombus
    }
}
public class Question_1 {
    public static void main(String[] args) {
        Polygon p1 = new Polygon();
    }
}