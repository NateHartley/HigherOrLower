import java.util.*;

public class hl {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // Create scanner obj
        Random rand = new Random();

        while(true) {
            int score = 0;

            while(true) {
                int guess1 = rand.nextInt(11);
                System.out.println("The computer has picked the number "+guess1);
                int guess2 = rand.nextInt(11);
        
                System.out.println("Is the computer's second number going to be higher (h) or lower (l) than the first? ");
                String highlow = input.nextLine();
        
                if (highlow.equals("h") || highlow.equals("l")) {
                    if (guess1 > guess2 && highlow.equals("l")) {
                        System.out.println("Correct! "+guess2+" is smaller than "+guess1);
                        score = score + 100;
                        System.out.println("+ 100 points!");
                        System.out.println("Your score = "+score+"\n");
                    } else if (guess1 < guess2 && highlow.equals("h")) {
                        System.out.println("Correct! "+guess2+" is larger than "+guess1);
                        score = score + 100;
                        System.out.println("+ 100 points!");
                        System.out.println("Your score = "+score+"\n");
                    } else if (guess1 > guess2 && highlow.equals("h")) {
                        System.out.println("Wrong! "+guess2+" is smaller than "+guess1);
                        System.out.println("You finished the game with a score of "+score+"\n");
                        break;
                    } else if (guess1 < guess2 && highlow.equals("l")) {
                        System.out.println("Wrong! "+guess2+" is larger than "+guess1);
                        System.out.println("You finished the game with a score of "+score+"\n");
                        break;
                    } else {
                        System.out.println("The numbers are the same!");
                        System.out.println("+ 0 points \n");
                    }
                } else {
                    System.out.println("Please chose either higher (h) or lower (l)");
                }                
            }
    
            System.out.println("Play again? (y/n) ");
            String yn = input.nextLine();
            if (yn.equals("n")) {
                break;
            }
        }        
    }
}
  