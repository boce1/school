import java.util.Scanner;

public class BMIcalculator {
    public static void main(String[] args)
    {
        // 227.0761 lbs
        // 71.25984 inch
        Scanner sc = new Scanner(System.in);
        printIntroduction();

        double index = getBMI(sc);
        //double mass = arr[0];
        //double height = arr[1];

        String stat = getStatus(index);

        ReportResults(index, stat);

    }  
    
    public static void printIntroduction()
    {
        System.out.println("This program calculates BMI");
    }

    public static double getBMI(Scanner sc)
    {
        double mass, height;
        System.out.print("Mass: ");
        mass = sc.nextDouble();
        System.out.print("Height: ");
        height = sc.nextDouble();

        //double[] out = {mass, height};

        return bmiFor(mass, height);
    }

    public static double bmiFor(double mass, double height)
    {
        return mass*703/ (height*height);
    }

    public static String getStatus(double index)
    {
        String status = new String();
        status = "None";
        if(index <= 18.5)
        {
            status = "undeweight";
        }else if(index <= 25)
        {
            status = "Normal";
        }else if(index <= 30)
        {
            status = "overweight";
        }else
        {
            status = "obbese";
        }

        return status;
    }

    public static void ReportResults(double index, String status)
    {
        double roundOff = Math.round(index * 100.0) / 100.0;
        System.out.println("Index " + roundOff + "\nStatus " + status);
    }
}
