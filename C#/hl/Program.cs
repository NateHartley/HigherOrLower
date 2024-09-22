using System.Globalization;

public class ConsoleApp1
{
    
    private static void Main(string[] args)
    {
        Random rnd = new Random();
        Console.WriteLine(" ");
        Console.WriteLine("Welcome to Higher or Lower!");
        Console.WriteLine("The aim of the game is to guess if the next number will be higher or lower than the previous.");
        Console.WriteLine(" ");
        Console.WriteLine("Lets begin...");
        Console.WriteLine(" ");
        
        int number1 = rnd.Next(10);
        int number2 = rnd.Next(10);
        Console.WriteLine("The computer picks a number between 0 and 10: "+number1);
        Console.WriteLine("Will the next number be Higher (h) or Lower (l) than {0} ?",number1);

        string guess = Console.ReadLine();
        Console.WriteLine(">>>"+guess);
                
        if (number2 > number1)
        {
            // Higher Wins
            string result1 = (guess == "h") ? "Correct!" : "You lose!";
            Console.WriteLine(result1);
            
        } else if (number1 > number2)
        {
            // Lower Wins
            string result2 = (guess == "l") ? "Correct!" : "You lose!";
            Console.WriteLine(result2);
        }
        else
        {
            Console.WriteLine("numbers are the same");
        }

        
        // if guess is not h or l
        
        if (guess != "h" | guess != "l"){
            Console.WriteLine("You have not picked h or l.");
            System.Environment.Exit(0);
        }
    }
}