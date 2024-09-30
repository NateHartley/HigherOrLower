const prompt = require("prompt-sync")({sigint: true})

while (1) {
    var score = 0;

    while (1) {
        var guess1 = Math.floor(Math.random() * 11);
        console.log("The computer has picked the random number", guess1);
        var guess2 = Math.floor(Math.random() * 11);
    
        var highlow = prompt("Is the computer's second number going to be higher (h) or lower (l) than the first? ");
        console.log("")

        if (highlow == "h" || highlow == "l") {
            if (guess1 > guess2 && highlow == "l") {
                console.log("Correct! "+guess2+" is smaller than "+guess1);
                score = score + 100;
                console.log("+ 100 points!");
                console.log("Your score = "+score+"\n");
            } else if (guess1 < guess2 && highlow == "h") {
                console.log("Correct! "+guess2+" is larger than "+guess1);
                score = score + 100;
                console.log("+ 100 points!");
                console.log("Your score = "+score+"\n");
            } else if (guess1 > guess2 && highlow == "h") {
                console.log("Wrong! "+guess2+" is smaller than "+guess1);
                console.log("You finished the game with a score of "+score+"\n");
                break;
            } else if (guess1 < guess2 && highlow == "l") {
                console.log("Wrong! "+guess2+" is larger than "+guess1);
                console.log("You finished the game with a score of "+score+"\n");
                break;
            } else {
                console.log("Both random numbers are the same! "+guess1+" and "+guess2);
                console.log("+ 0 points \n");
            }
        } else {
            console.log("Please chose either higher (h) or lower (l)");
        }
    }
    
    var yn = prompt("Play again? (y/n) ")
    if (yn == "n") {
        break;
    }
}
