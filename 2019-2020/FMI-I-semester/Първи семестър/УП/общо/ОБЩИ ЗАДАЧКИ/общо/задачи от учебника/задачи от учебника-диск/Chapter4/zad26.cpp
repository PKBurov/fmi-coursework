char* normalize(char* text)
{
    int i = 0;
    for(int j = 0; text[j]; ++j)
    {
        text[i++] = text[j];
        if(text[j] == ' ')
        {
            while (text[j] == ' ') 
                ++j;
            --j;
        }
    }
    text[i] = '\0';
    return text;
}
