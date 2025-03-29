#include "Text.h"

Text::Text() {}

void Text::setFont(sf::Font& font) {
    mFont = font;
    mText.setFont(mFont); // Make sure the font is assigned
}

sf::Text* Text::getText() {
    return &mText;
}
