using System.Globalization;

public class HigherLower
{
    
    private static void Main(string[] args)
    {
        while(true) {

            int score = 0;

            while(true) {
                Random rnd = new Random();
                int number1 = rnd.Next(10);
                int number2 = rnd.Next(10);
                Console.WriteLine("The computer is picking a number between 0 and 10...");
                Console.WriteLine("Will the next number be Higher (h) or Lower (l) than {0} ?",number1);

                string guess = Console.ReadLine();

                // If guess is not h or l
                if (guess != "h" & guess != "l"){
                    Console.WriteLine("You have not picked h or l. Game over.");
                    System.Environment.Exit(0);
                }
                        
                if (number2 > number1) {
                    // Higher Wins
                    if (guess == "h") {
                        Console.WriteLine("Correct! {0} is higher than {1}",number2,number1);
                        Console.WriteLine("+100 added to your score");
                        score += 100;
                    } else {
                        Console.WriteLine("Incorrect! {0} is not lower than {1}",number2,number1);
                        Console.WriteLine("You finished the game with {0} points",score);
                        break;
                    }
                } else if (number1 > number2) {
                    // Lower Wins
                    if (guess == "h") {
                        Console.WriteLine("Incorrect! {0} is not lower than {1}",number2,number1);
                        Console.WriteLine("You finished the game with {0} points",score);
                        break;
                    } else {
                        Console.WriteLine("Correct! {0} is higher than {1}",number2,number1);
                        Console.WriteLine("+100 added to your score");
                        score += 100;
                    }
                }
                else {
                    Console.WriteLine("The numbers are the same! No score added.");
                }
            }

            Console.WriteLine("Play again? (y/n) ");
            string yn = Console.ReadLine();
            if (yn == "n") {
                System.Environment.Exit(0);
            }
        }
    }
}