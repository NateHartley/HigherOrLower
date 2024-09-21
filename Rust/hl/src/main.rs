use rand::{rngs::ThreadRng, Rng};

fn main() {

    println!("\n#-------------- Higher or Lower --------------#\n");

    let mut score = 0;
    let mut i = 0;

    // Random number gen
    let mut random: ThreadRng = rand::thread_rng();
    let mut guess1 = random.gen_range(0..11);
    let mut guess2 = random.gen_range(0..11);
    println!("\nThe computer has picked the number {}.", guess1);

    while i < 1 {

        // User input
        println!("\nIs the next number higher (h) or lower (l) than {}?", guess1);
        let mut input = String::new();
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();

        if (guess1 > guess2) & (input.trim() == "l") {
            println!("\nCorrect! The number was {}", guess2);
            score = score + 10;
            println!("Current score: {}", score);
            guess1 = guess2;
            guess2 = random.gen_range(0..11);

        } else if (guess1 > guess2) & (input.trim() == "h") {
            println!("\nIncorrect! {} is lower than {}", guess2, guess1);
            println!("Final score: {}", score);
            i = i + 1

        } else if (guess1 < guess2) & (input.trim() == "h") {
            println!("\nCorrect! {} is higher than {}", guess2, guess1);
            score = score + 10;
            println!("Current score: {}", score);
            guess1 = guess2;
            guess2 = random.gen_range(0..11);

        } else if (guess1 < guess2) & (input.trim() == "l") {
            println!("\nIncorrect! {} is higher than {}", guess2, guess1);
            println!("Final score: {}", score);
            i = i + 1
            
        } else {
            println!("Not a valid input.");
        }
    }
}