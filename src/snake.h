#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define SNAKE_SIZE 3

typedef struct SnakeBody SnakeBody;
struct SnakeBody
{
    uint8_t x;
    uint8_t y;
    uint8_t dir;
};
