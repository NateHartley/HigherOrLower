package main

import (
	"fmt"
	"math/rand/v2"
)

func main() {
	var highlow string
	var yn string

	for {
		var score = 0
		fmt.Println(">>0")

		for {
			fmt.Println()
			fmt.Println("-----------------------------------")
			guess1 := rand.IntN(11)
			fmt.Println("The program has picked the number", guess1)
			fmt.Println("Is the next number going to be higher (h) or lower (l) than", guess1, "?")
			fmt.Scan(&highlow)
			guess2 := rand.IntN(11)

			if highlow == "h" || highlow == "l" {
				if highlow == "h" && guess2 > guess1 {
					fmt.Println("Correct!", guess2, "is larger than", guess1)
					score = score + 100
					fmt.Println("+100 points!")
					fmt.Println("Your score =", score)
				} else if highlow == "h" && guess2 < guess1 {
					fmt.Println("Wrong!", guess2, "is smaller than", guess1)
					fmt.Println("You finished the game with a score of", score)
					break
				} else if highlow == "l" && guess1 > guess2 {
					fmt.Println("Correct!", guess2, "is smaller than", guess1)
					score = score + 100
					fmt.Println("+100 points!")
					fmt.Println("Your score =", score)
				} else if highlow == "l" && guess1 < guess2 {
					fmt.Println("Wrong!", guess2, "is larger than", guess1)
					fmt.Println("You finished the game with a score of", score)
					break
				} else {
					fmt.Println(guess1, "and", guess2, "are the same!")
					fmt.Println("+0 points")
					fmt.Println("Your score =", score)
				}
			} else {
				fmt.Println("Invalid input. Must be either higher (h) or lower (l)")
			}
		}

		fmt.Println()
		fmt.Println("Would you like to play again? (y/n)")
		fmt.Scan(&yn)
		if yn == "n" {
			break
		}
		score = 0
		fmt.Println(">>0")
	}

}
