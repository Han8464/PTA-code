import java.util.Scanner;

class Deep{
    public int n;
    public int g[][];
    public int d[][];

    public int getDeep(int root){
        for(int i = 1; i <= n; i++)
        {

        }

    }

    public int Deepest(){
        for(int i = 1; i <= n; i++){
            getDeep(i);
        }

    }



}

public class Main {
    public static void main(String args[]){
        Deep deep = new Deep();
        Scanner sc = new Scanner(System.in);
        deep.n = sc.nextInt();
        deep.g = new int[deep.n + 1][deep.n + 1];
        deep.d = new int[deep.n + 1][deep.n + 1];
        for(int i = 1; i < deep.n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            deep.g[a][b] = deep.g[b][a] = 1;
        }


    }
}
