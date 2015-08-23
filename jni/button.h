#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string.h>

class Button{

public:

    /* Initialize the private variables */
    Button(){
        text.setString("");
        clicked = false;
        is_clicked = false;
        clickEffect = true;

    /* if(!font.loadFromFile("defaultFont.otf")){ std::cerr << "Can't find the font file" << std::endl; }
        else setFont(font); setCharacterSize(30); setTextColor(sf::Color::White);

        if(!texture.loadFromFile("defaultButton.png")) std::cerr << "Default texture not loaded" << std::endl;
        else sprite.setTexture(texture);

        if(!pressed_texture.loadFromFile("defaultPressedButton.png")) std::cerr << "presedButton text. not loaded" << std::endl;
    */
        setPosition(0,0);
    }

    /* Set the size passed as parameter */
    void setSize(sf::Vector2f size){
        sprite.setScale(size.x/sprite.getGlobalBounds().width, size.y/sprite.getGlobalBounds().height);
        this->setText(text.getString());
    }
    void setSize(float x, float y){ setSize(sf::Vector2f(x,y));}

    /* Return the size of the button*/
    sf::Vector2f getSize(){
        return sf::Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height);
    }
    /* The return indicates if the button is
    clicked or not*/
    bool isClicked(){ return is_clicked; }

    /* Set the position of the button */
    void setPosition(sf::Vector2f position){
        sprite.setPosition(position);
        text.setPosition(position.x +
                        sprite.getGlobalBounds().width/2 -
                        text.getGlobalBounds().width/2,
            position.y + sprite.getGlobalBounds().height/2 - (text.getGlobalBounds().height/2));
    }
    void setPosition(float x, float y){
        setPosition(sf::Vector2f(x, y));
    }

    /* Return the position of the button*/
    sf::Vector2f getPosition(){
        return sprite.getPosition();
    }

    /* Return true if the button has been clicked */
    bool hasBeenClicked(){
        bool r = clicked;
        if(clicked) clicked = false;
        return r;
    }

    /* Return the time since the last time the button
    has been clicked (returned in a float as seconds)*/
    float timeSinceLastClick(){ return clock.getElapsedTime().asSeconds(); }

    /* Set the text on the button */
    void setText(std::string s){
        text.setString(s);
        if(s.size() != 0){
            float actualCharSize, desiredCharSize;
            float actualTextSize, desiredTextSize;
            actualCharSize = text.getCharacterSize();
            actualTextSize = text.getGlobalBounds().width+2;
            desiredTextSize = sprite.getGlobalBounds().width;
            desiredCharSize = actualCharSize*desiredTextSize/actualTextSize;
            text.setCharacterSize(desiredCharSize);
        }
    }

    /* Returns the string setted on the text*/
    std::string getText(){ return text.getString();}
    
    /* Set the text on the button and scale the button 
    so the text fits on it */
    void setTextResize(std::string s){
        text.setString(s);
        if(s.size() != 0){
            float actualTextSize, factor;
            actualTextSize = text.getGlobalBounds().width;
            //WTF THIS 10?¿?¿?¿? well... it works :$
            factor = (actualTextSize)/10/sprite.getGlobalBounds().width;
            sprite.setScale(factor, factor);
        }
    }

    /* Enable the change of texture when the button is clicked */
    void enableClickEffect(){ clickEffect = true; }

    /* Disable the change of texture when the button is clicked */
    void disableClickEffect(){ clickEffect = false; }

    /* Returns wether ClickEffect is activated or not */
    bool clickEffectActivated(){ return clickEffect; }

    /* Set the size of the characters of the button text*/
    void setCharacterSize(uint u){ text.setCharacterSize(u); }

    /* Returns the characterSize*/
    uint getCharacterSize(){ return text.getCharacterSize(); }

    /* Set the color of the button's text*/
    void setTextColor(sf::Color c){text.setColor(c);}

    /* Returns the color of the button's text*/
    sf::Color getTextColor(){ return text.getColor(); }

    /*Set the Font passed as a parameter as the one used by the button*/
    void setFont(sf::Font f){ font = f; text.setFont(font); }

    /* Set the Texture that will be used as default button image */
    void setTexture(std::string name){
    if(!texture.loadFromFile(name)) std::cerr << "Default texture not loaded on setTexture" << std::endl;
    else sprite.setTexture(texture); }
    
    /* Set the Texture that will be used as default button pressed image */
    void setPressedTexture(std::string name){
    if(!pressed_texture.loadFromFile(name)) std::cerr << "presedButton text. not loaded on Setter" << std::endl; }

    /* Draw the button on the window passed as parameter */
    void draw(sf::RenderWindow &w){
        sf::Vector2f position = getPosition();
        text.setPosition(position.x + sprite.getGlobalBounds().width/2 - text.getGlobalBounds().width/2, position.y + sprite.getGlobalBounds().height/2 - text.getGlobalBounds().height);
        w.draw(sprite);
        w.draw(text);
    }

    /* Update the private variables if needed acordingly to the event*/
    void handleEvent(sf::Event e){
    
        float delayx, delayy;
        delayx = sprite.getOrigin().x*sprite.getScale().x;
        delayy = sprite.getOrigin().y*sprite.getScale().y;
        sprite.move(-delayx, -delayy);
        if(e.type == sf::Event::MouseButtonPressed){
            if (e.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f click(e.mouseButton.x, e.mouseButton.y);
                if(click.x > sprite.getPosition().x && click.x < sprite.getPosition().x+sprite.getGlobalBounds().width){
                    if(click.y > sprite.getPosition().y && click.y < sprite.getPosition().y+sprite.getGlobalBounds().height){
                        clicked = true;
                        is_clicked = true;
                        clock.restart();
                        if(clickEffect && sprite.getTexture() == &texture) sprite.setTexture(pressed_texture);
                    }
                }
            }

        }
        if(e.type == sf::Event::MouseButtonReleased){
            if (e.mouseButton.button == sf::Mouse::Left) {
                is_clicked = false;
                if(clickEffect && sprite.getTexture() != &texture) sprite.setTexture(texture);
            }
        }
        if(e.type == sf::Event::TouchBegan){
            if (sf::Touch::isDown(0)) {
            sf::Vector2i position = sf::Touch::getPosition(0);
            sf::Vector2f tclick(position.x, position.y);
                if(tclick.x > sprite.getPosition().x && tclick.x < sprite.getPosition().x+sprite.getGlobalBounds().width){
                    if(tclick.y > sprite.getPosition().y && tclick.y < sprite.getPosition().y+sprite.getGlobalBounds().height){
                        clicked = true;
                        is_clicked = true;
                        clock.restart();
                        if(clickEffect && sprite.getTexture() == &texture) sprite.setTexture(pressed_texture);
                    }
                }
            }
        }
        if(e.type == sf::Event::TouchEnded){
            is_clicked = false;
            if(clickEffect && sprite.getTexture() != &texture) sprite.setTexture(texture);
        }
        sprite.move(delayx, delayy);
    }
    
    void setOrigin(sf::Vector2f origin){
        sprite.setOrigin(origin);
    }

private:

    bool clicked;
    bool is_clicked;
    bool clickEffect;

    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture pressed_texture;
    float time_since_last_click;

};

#endif // BUTTON_H
