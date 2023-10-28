import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		
		String name = sc.nextLine();
		String age = sc.nextLine();
		String uni = sc.nextLine();
		String[] arr = new String[3];

		
        arr[0] = name;
        arr[1] = age;
        arr[2] = uni;

        for(int i = 0; i < 3; i++)
		{
			System.out.println(arr[i]);
		}

		System.out.println("Your name is " + name);
        System.out.println("Your age is " + age);
		System.out.println("Your uni is " + uni);
	}

}
