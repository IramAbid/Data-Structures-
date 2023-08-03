// Iram Abid
//20COB051
//SERIAL NO-06
import java.util.Scanner;

import static java.lang.System.exit;

abstract class Shape{
    public abstract void numberOfSides();
}

class Triangle extends Shape{
    double a,b,c;
    Triangle(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter side Length of Triangle : ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        try{
            if(a<0||b<0||c<0){
                throw new Exception("Negative values are not allowed");
            }
        }catch (Exception e){
            System.out.println(e);
            exit(0);
        }
    }
    @Override
    public void numberOfSides(){
        int sides = 3;
    }
    public double perimeter(){
        return a+b+c;
    }
}

class Trapezoid extends Shape{
    double a,b,c,d;
    Trapezoid(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter side Length of Trapezoid : ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        d = sc.nextDouble();
        try{
            if(a<0||b<0||c<0||d<0){
                throw new Exception("Negative values are not allowed");
            }
        }catch (Exception e){
            System.out.println(e);
            exit(0);
        }
    }
    @Override
    public void numberOfSides(){
        int sides = 4;
    }
    public double perimeter(){
        return a+b+c+d;
    }
}

class Hexagon extends Shape{
    double a,b,c,d,e;
    Hexagon(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter side Length of Hexagon : ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        d = sc.nextDouble();
        e = sc.nextDouble();
        try{
            if(a<0||b<0||c<0||d<0||e<0){
                throw new Exception("Negative values are not allowed");
            }
        }catch (Exception e){
            System.out.println(e);
            exit(0);
        }
    }
    @Override
    public void numberOfSides(){
        int sides = 4;
    }
    public double perimeter(){
        return a+b+c+d+e;
    }
}

public class Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of sides : ");
        int sides = sc.nextInt();
        try{
            if(sides<3||sides>5){
                throw new Exception("Invalid Number of Sides!");
            }
            if(sides == 3){
                Triangle t1 = new Triangle();
                System.out.println("Perimeter of Triangle is : "+t1.perimeter());
            }
            else if(sides == 4){
                Trapezoid tp1 = new Trapezoid();
                System.out.println("Perimeter of Trapezoid is : "+tp1.perimeter());
            }
            else{
                Hexagon h1 = new Hexagon();
                System.out.println("Perimeter of Hexagon is : "+h1.perimeter());
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
