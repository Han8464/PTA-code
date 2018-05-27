
import java.util.Scanner;

public class solution {
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        format(a,b);
    }
    public static void format(int a, int b)
    {
        int sumInt = a + b;
        String sumString = "" + sumInt;
        int length = sumString.length();

        for (int i = length; i > 3; i = i - 3)
        {
            StringBuffer tmp =  new StringBuffer();
            if (i == 4){
                if (!sumString.startsWith("-")) {
                    tmp.append(sumString).insert(i - 3, ",");
                    sumString = tmp.toString();
                }
            }else
            {
                tmp.append(sumString).insert(i - 3, ",");
                sumString = tmp.toString();
            }
        }
        System.out.print(sumString);
    }
}
