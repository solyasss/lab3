
class Game
{
private:
    int **reels; 
    int max_length;
    int *lengths;
    int *first_element;  
    int *last_element;

public:
    Game(int g);
    ~Game();
    void clear(int index);
    bool empty(int index);
    bool full(int index);
    int get_count(int index);
    void push(int index, int value);
    int swap(int index);
    int get_value(int index, int element);
};

