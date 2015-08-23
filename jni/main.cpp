//GRAVITY
#include <time.h>       /* time */
#include <string>       /*strings*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "button.h"
#include "Portada.hpp"
#include "TextScreen.hpp"
#include "MenuSelection.hpp"


namespace kind {
    enum kindOfSentence {
        random,
        party,
        drinking,
        erotic,
        qttyKinds
    };
}

std::vector < std::vector<std::string> > frases (kind::qttyKinds);
//THIS IS NOT BEAUTIFULL BUT I NEED IT FOR ANDROID VERSION T.T
void loadFrases(){
frases[kind::party].push_back("Serve a drink to the one who accussed you");
frases[kind::party].push_back("Sing a song for us");
frases[kind::party].push_back("Show us your toe wow so intense");
frases[kind::party].push_back("Run around the room imitating a monkey");
frases[kind::party].push_back("Take off a cloth");
frases[kind::party].push_back("Lick someone in the room");
frases[kind::party].push_back("Exchange an article of clothing \nwith someone in the room");
frases[kind::party].push_back("Walk around the room like a dog and bark");
frases[kind::party].push_back("High-five everyone in the room");
frases[kind::party].push_back("Exchange clothes with a member of the opposite sex");
frases[kind::party].push_back("Do the robot dance");
frases[kind::party].push_back("Put an ice cube down your shirt");
frases[kind::party].push_back("Put an ice cube down your pants");
frases[kind::party].push_back("Look for something to wear as a hat \n and wear it (it can't be a hat)");
frases[kind::party].push_back("Act as if you were a Cat");
frases[kind::party].push_back("Hug someone on the room very hard");
frases[kind::party].push_back("Answer, If you weren't here, what would you be doing?");
frases[kind::party].push_back("Exchange shirts with someone on the room");
frases[kind::party].push_back("Drink a mystery brew concocted by the rest of the group");
frases[kind::party].push_back("Wear your pants backward for a while");
frases[kind::party].push_back("You don't have to do anything \n just kidding, press the button again");
frases[kind::party].push_back("Pretend someone’s hair is your crush and ask it out");
frases[kind::party].push_back("Tell us your best joke.");
frases[kind::party].push_back("Run to the nearest store or neighbour in a panic \nand ask them if they’ve got a goldfish first aid kit");
frases[kind::party].push_back("Put a piece of ice down your shirt and dance until it shakes out.");
frases[kind::party].push_back("Call up a friend and tell them \nhow excited you are about armpits");
frases[kind::party].push_back("Start singing a pop song out loud like you’re singing opera");
frases[kind::party].push_back("Put pepper on your tongue and swallow.");
frases[kind::party].push_back("HANDBONING!!!");
frases[kind::party].push_back("Kiss everyone’s knees");
frases[kind::party].push_back("Put makeup on someone \nwith your eyes closed");
frases[kind::party].push_back("Claim that you will forever serve lord Penguin");
frases[kind::party].push_back("Let everyone in the room tickle you");
frases[kind::party].push_back("Let someone ride you like a horse around the room");
frases[kind::party].push_back("Put an ice cube in your pants pocket \nand keep it there until it completely melts.");
frases[kind::party].push_back("Tell a bad joke in a really enthusiastic way");
frases[kind::party].push_back("Take an item of food from the refrigerator \nand kiss it passionately for 90 seconds.");
frases[kind::party].push_back("Give a hug to someone and refuse to let go");
frases[kind::party].push_back("Put an ice cube no your butt");



frases[kind::random].push_back("Deal With It...");
frases[kind::random].push_back("Sing a song for us");
frases[kind::random].push_back("Show us your toe wow so intense");
frases[kind::random].push_back("Tell us your biggest fear");
frases[kind::random].push_back("Serve a drink to the one who accussed you");
frases[kind::random].push_back("Make ten push-ups");
frases[kind::random].push_back("Look for something to wear as a hat \n and wear it (it can't be a hat)");
frases[kind::random].push_back("Act as if you were a Cat");
frases[kind::random].push_back("Hug someone on the room very hard");
frases[kind::random].push_back("Explain the job of your dreams");
frases[kind::random].push_back("Answer, How old were you when you had your first kiss?");
frases[kind::random].push_back("Answer, Have you ever stolen anything?");
frases[kind::random].push_back("What do you think is your biggest physical flaw");
frases[kind::random].push_back("Answer, If you weren't here, what would you be doing?");
frases[kind::random].push_back("Exchange shirts with someone on the room");
frases[kind::random].push_back("Drink a mystery brew concocted by the rest of the group");
frases[kind::random].push_back("Wear your pants backward for a while");
frases[kind::random].push_back("Run around the room imitating a monkey");
frases[kind::random].push_back("Take off a cloth");
frases[kind::random].push_back("Try to seduce someone on the room");
frases[kind::random].push_back("Lick someone on the room");
frases[kind::random].push_back("Exchange an article of clothing \nwith someone on the room");
frases[kind::random].push_back("Walk around the room like a dog and bark");
frases[kind::random].push_back("Hug everyone on the room");
frases[kind::random].push_back("High-five everyone in the room");
frases[kind::random].push_back("Exchange clothes with a member of the opposite sex");
frases[kind::random].push_back("Do the robot dance");
frases[kind::random].push_back("Suck your thumb and cry like a baby");
frases[kind::random].push_back("Put an ice cube down your shirt");
frases[kind::random].push_back("Put an ice cube down your pants");
frases[kind::random].push_back("Do 25 push ups");
frases[kind::random].push_back("Answer, Which person in the room do you think \nis most likely to succeed and why?");
frases[kind::random].push_back("Answer, Who do you think is Hot?");
frases[kind::random].push_back("Answer, What is your favorite thing to lick?");
frases[kind::random].push_back("Answer, What is you favorite possession?");
frases[kind::random].push_back("Tell us something you like about your body.");
frases[kind::random].push_back("You don't have to do anything \n just kidding, press the button again");
frases[kind::random].push_back("Answer, how many guys have you slept with? How many girls?");
frases[kind::random].push_back("Answer, how old was the oldest person you have slept with?");
frases[kind::random].push_back("Put a piece of ice down your shirt and dance until it shakes out.");
frases[kind::random].push_back("Run to the nearest store or neighbour in a panic \nand ask them if they’ve got a goldfish first aid kit");
frases[kind::random].push_back("Call up a friend and tell them \nhow excited you are about armpits");
frases[kind::random].push_back("Pretend someone’s hair is your crush and ask it out");
frases[kind::random].push_back("Start singing a pop song out loud like you’re singing opera");
frases[kind::random].push_back("Wear all your clothes inside out");
frases[kind::random].push_back("Put pepper on your tongue and swallow.");
frases[kind::random].push_back("Pretend to be a pig and start sniffing \nall over the people in your group");
frases[kind::random].push_back("Kiss everyone’s knees");
frases[kind::random].push_back("Put makeup on someone \nwith your eyes closed");
frases[kind::random].push_back("Sniff your friend’s socks \nwhile they’re still wearing them");
frases[kind::random].push_back("Answer, Have you ever gotten a boner in class?");
frases[kind::random].push_back("Answer, What is you favorite possession?");
frases[kind::random].push_back("Say something about rabbits");
frases[kind::random].push_back("Say something about penguins");
frases[kind::random].push_back("Massage someone’s feet with your feet");
frases[kind::random].push_back("Claim that you will forever serve lord Penguin");
frases[kind::random].push_back("Kiss and lick a beer bottle as though you are giving a blowjob");
frases[kind::random].push_back("Let everyone in the room tickle you");
frases[kind::random].push_back("The player who accused you has to draw \na mustache on you");
frases[kind::random].push_back("The player who accused you has to draw \nan unibrow on you");
frases[kind::random].push_back("Let someone ride you like a horse around the room");
frases[kind::random].push_back("Put an ice cube in your pants pocket \nand keep it there until it completely melts.");
frases[kind::random].push_back("Take an item of food from the refrigerator \nand kiss it passionately for 90 seconds.");
frases[kind::random].push_back("Give a hug to someone and refuse to let go");
frases[kind::random].push_back("Answer, If you had 1,000,000 dollars to give away, how would you do it?");
frases[kind::random].push_back("Put an ice cube no your butt");




frases[kind::drinking].push_back("You don't have to do anything \n just kidding, press the button again");
frases[kind::drinking].push_back("Put an ice cube down your shirt");
frases[kind::drinking].push_back("Put an ice cube down your pants");
frases[kind::drinking].push_back("Drink a mystery brew concocted by the rest of the group");
frases[kind::drinking].push_back("Serve a drink to the one who accussed you");
frases[kind::drinking].push_back("Drink a cup in less than 5 seconds");
frases[kind::drinking].push_back("Drink a cup in less than 5 seconds");
frases[kind::drinking].push_back("Drink a cup in less than 10 seconds");
frases[kind::drinking].push_back("Drink a cup in less than 10 seconds");
frases[kind::drinking].push_back("Drink a cup in less than 15 seconds");
frases[kind::drinking].push_back("Drink all you have in your glass");
frases[kind::drinking].push_back("Drink all you have in your glass");
frases[kind::drinking].push_back("Drink all you have in your glass");
frases[kind::drinking].push_back("Drink all you have in your glass");
frases[kind::drinking].push_back("Drink all you have in your glass");
frases[kind::drinking].push_back("Drink all of your friend’s drinks");
frases[kind::drinking].push_back("Kiss and lick a beer bottle as though you are giving a blowjob, then drink it");
frases[kind::drinking].push_back("Let someone ride you like a horse around the room");
frases[kind::drinking].push_back("Tell a bad joke in a really enthusiastic way");
frases[kind::drinking].push_back("Put an ice cube into your butt");
frases[kind::drinking].push_back("The one who acused you will prepare you a drink");
frases[kind::drinking].push_back("Drink from another person glass");


frases[kind::erotic].push_back("You don't have to do anything \n just kidding, press the button again");
frases[kind::erotic].push_back("Take off a cloth");
frases[kind::erotic].push_back("Lick someone in the room");
frases[kind::erotic].push_back("Answer, Who do you think is Hot?");
frases[kind::erotic].push_back("Answer, What is your favorite thing to lick?");
frases[kind::erotic].push_back("Put an ice cube down your pants");
frases[kind::erotic].push_back("Put an ice cube down your underwear");
frases[kind::erotic].push_back("Try to seduce someone on the room");
frases[kind::erotic].push_back("Kiss the person on your right");
frases[kind::erotic].push_back("Answer, How old were you when you had your first time?");
frases[kind::erotic].push_back("Show us your toe wow so intense");
frases[kind::erotic].push_back("Answer, Are you a virgin?");
frases[kind::erotic].push_back("Demonstrate your favorite sexual position with \nsomeone on the room");
frases[kind::erotic].push_back("Touch someone’s nipples");
frases[kind::erotic].push_back("Kiss somebody's ass");
frases[kind::erotic].push_back("Suck the finger of the player who acused you sensually");
frases[kind::erotic].push_back("Do you own any sextoys? How many?");
frases[kind::erotic].push_back("Rub asses with the player who acused you");
frases[kind::erotic].push_back("Rub noses with the player who acused you");
frases[kind::erotic].push_back("Kiss somebody for at least 5 seconds (Bonus, Mouth Kiss)");
frases[kind::erotic].push_back("Lick the bellybutton of the player who acused you");
frases[kind::erotic].push_back("You're a slave now, you can not choose your own master. \nThe group will!");
frases[kind::erotic].push_back("Slap someone’s ass");
frases[kind::erotic].push_back("Gently lick the ear of the person who accused you");
frases[kind::erotic].push_back("Pretend you’re having an orgasmic moment \nand start acting it out");
frases[kind::erotic].push_back("Spend the next round sitting in the lap \nof the player who accused you");
frases[kind::erotic].push_back("Kiss and lick a beer bottle as though you are giving a blowjob");
frases[kind::erotic].push_back("Let everyone in the room tickle you");
frases[kind::erotic].push_back("Get someone to kiss you anywhere they choose");
frases[kind::erotic].push_back("Answer, How was your first time?");
frases[kind::erotic].push_back("Answer, Your favorite body part on a woman is?");
frases[kind::erotic].push_back("Answer, Where is the most public place you have had sex?");
frases[kind::erotic].push_back("Answer, What is your favorite position?");
frases[kind::erotic].push_back("Answer, Have you ever kissed or had sex with someone of the same sex?");
frases[kind::erotic].push_back("Answer, Have you ever had sex blindfolded?");
frases[kind::erotic].push_back("Answer, Who’s the last person you \nundressed in your thoughts?");
frases[kind::erotic].push_back("Make a massage where you want on \n the person that acused you");
frases[kind::erotic].push_back("Hug and rubb passionately with someone");
frases[kind::erotic].push_back("Kiss someone");
frases[kind::erotic].push_back("Kiss someone passionately");
frases[kind::erotic].push_back("Ask someone to do something you would like to do");

//     frases[kind::random].push_back("");
}

std::string getFrase(int kind){
    
    int num = rand()%frases[kind].size();
    return frases[kind][num];
    
}


int main(int argc, const char* argv[]){
    
    loadFrases();   
    srand (time(NULL));
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Who is the monster?");
    sf::Vector2f screenSize = sf::Vector2f(window.getSize().x,window.getSize().y);    
    float deltatime = 0;
    
    Portada portada;
    
    //Cover
    portada.notAnimation();
    portada.display(&window, "res/pics/whoisthemonster.jpg");
    //Credits
    portada.display(&window, "res/pics/credits.png");
    
    //Rules
    portada.animation();
    portada.display(&window, "res/pics/rules1.png");
    portada.display(&window, "res/pics/rules2.png");  
    
    //GAME
    
//     float deltatime;
//     sf::Clock timer;
    int kind = kind::random;
    MenuSelection kindSelector;
    std::vector<std::string> kinds;
    //same order as enum.
    kinds.push_back(" random ");
    kinds.push_back("  party  ");
    kinds.push_back(" drinking ");
    kinds.push_back(" erotic ");
    kind = kindSelector.select(&window, kinds);
    
    Button button;
    button.setTexture("res/pics/buttons/buttonReleassed.png");
    button.setPressedTexture("res/pics/buttons/buttonPressed.png");
    button.setOrigin(sf::Vector2f(button.getSize().x/2,button.getSize().y/2));
    button.setPosition(window.getSize().x/2,window.getSize().y/2);
    button.setSize(window.getSize().y/3,window.getSize().y/3);
    TextScreen textScreen;
    
    while(window.isOpen()){
        
//         deltatime = timer.restart().asSeconds();
        
        sf::Event event;
        while(window.pollEvent(event)) {
            button.handleEvent(event);
            if (event.type == sf::Event::Closed) window.close(); 
            if (event.type == sf::Event::Resized) {window.setSize(sf::Vector2u(event.size.width, event.size.height));}
            if (sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        
        if(!button.isClicked() && button.hasBeenClicked()){
            std::string frase = "You are The Monster!!! \n";
            frase+=getFrase(kind);
            textScreen.displayText(&window, frase, sf::Color::Black); 
        }
        
        window.clear();
        button.draw(window);
        window.display();
    }
}
