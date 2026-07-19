#include <iostream>
#include <vector>
#include <random>

// Basic structure for the enemies.
// Each enemy has a name and a health value.
struct Enemy {
    std::string name;
    int health;

    // Removes health from the enemy when it takes damage.
    void Damage(int damage) {
        health -= damage;
    }
};

// Basic structure for the player.
struct Player {
    int damage;
    int health = 10;

    // Removes health from the player.
    void damagi(int damagy) {
        health -= damagy;
    };
};

int main() {
    // Vector that stores all the enemies in the game.
    std::vector<Enemy> enemies;

    Player p;

    // Adding some enemies to start the game.
    enemies.push_back({ "zédentuço", 30 });
    enemies.push_back({ "MegaMente", 50 });

    // Controls whether the game is still running.
    bool running = true;

    while (running) {
        int option;

        // Main menu.
        std::cout << "\n1 - View enemies\n";
        std::cout << "2 - Attack an enemy\n";
        std::cout << "3 - Add an enemy\n";
        std::cout << "4 - Exit\n";

        std::cin >> option;

        switch (option) {

        // Displays all enemies stored in the vector.
        case 1:

            for (int i = 0; i < enemies.size(); i++) {
                std::cout << i << " - "
                    << enemies[i].name
                    << " | Health: "
                    << enemies[i].health
                    << '\n';
            }

            break;

        // Attack system.
        case 2: {
            int enemychoice;

            std::cout << "Which enemy do you want to attack: ";
            std::cin >> enemychoice;

            // Checks if the selected index exists in the vector.
            if (enemychoice >= 0 && enemychoice < enemies.size()) {

                // The selected enemy takes 10 damage.
                enemies[enemychoice].Damage(10);

                std::cout << enemies[enemychoice].name
                    << " now has "
                    << enemies[enemychoice].health
                    << " health.\n";
            }
            else {
                std::cout << "Invalid enemy!\n";
            }

            // Creating a random number generator.
            std::random_device rd;
            std::mt19937 R(rd());

            // The damage taken can be between 0 and 10.
            std::uniform_int_distribution<int> damage(0, 10);

            // Randomly generates the damage taken by the player.
            int damageTaken = damage(R);

            p.damagi(damageTaken);

            // If the damage is greater than zero, the player was hit.
            if (damageTaken > 0) {
                std::cout << "You were attacked! Your current health: "
                    << p.health << std::endl;
            }
            else {
                // If the damage is zero, the player successfully dodged.
                std::cout << "You dodged the attack!"
                    << std::endl;

                std::cout << "Your health is still: "
                    << p.health << std::endl;
            }

            break;
        }

        // Not implemented yet.
        case 3:
            break;

        // Stops the main loop and exits the game.
        case 4:
            running = false;
            break;

        // Runs when the user enters an option that does not exist.
        default:
            std::cout << "Invalid option!\n";
        }

        // If both enemies die, the game ends.
        if (enemies[0].health <= 0 and enemies[1].health <= 0)
            return 0;

        // If the player's health reaches zero, the player loses.
        if (p.health <= 0) {
            std::cout << "You died..."
                << std::endl;

            return 0;
        }
    }
}
