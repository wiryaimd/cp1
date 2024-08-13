import java.util.Scanner;

class Solution{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int n = scan.nextInt();

        int ask = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '*'){
                ask = i;
                break;
            }
        }

        s = s.substring(0, ask) + s.substring(ask + 1);

        for(int i = 0; i < n; i++){
            String a = scan.next();
            if(ask >= a.length() || s.length() - ask >= a.length()) continue;
            // System.out.println(a.length() - (s.length() - ask));
            // System.out.println(a.substring(a.length() - (s.length() - ask)));
            if(s.substring(0, ask).equals(a.substring(0, ask)) && s.substring(ask).equals(a.substring(a.length() - ask - 1))){
                System.out.println(a);
            }
        }

    }
}