#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/***************** Class Shape ***********************
    | attributes |
    | methods    |
*****************************************************/
// Attribute(s)
typedef struct Shape_t {
    const struct Vtbl_t *VtblPtr;
    int32_t pos_x;
    int32_t pos_y;
} Shape;

typedef struct Vtbl_t {
    void (* draw)(Shape *me);
    void (* move_to)(Shape *me, int32_t pos_x, int32_t pos_y);
} Vtbl;

// Method(s) - draw. Abstract method. Shall never be called.
void draw(Shape *me) 
{
    assert(0);
}

// Method(s) - move_to. Abstract method. Shall never tbe called.
void move_to(Shape *me, int32_t pos_x, int32_t pos_y) 
{
    assert(0);
}

// Method(s) - ctor
void ctor(Shape *me, int32_t pos_x, int32_t pos_y)
{
    static const Vtbl vTable = {
        .draw = draw, 
        .move_to = move_to,
    };
    me->VtblPtr = &vTable;
    me->pos_x = pos_x;
    me->pos_y = pos_y;
    printf("Calling Shape ctor...\r\n");
}

/**************** Class Rectangle ********************
    | attributes |
    | methods    |
*****************************************************/

// Attributes(s)
typedef struct Rectangle_t {
    Shape super;  // Inherited from Shape class.
    int32_t height;
    int32_t width;
} Rectangle;

// Method(s) - Overwrite draw().
void rec_draw(Shape *me) 
{
    printf("Draw a rectangle. "
           "Pos_x: %d, "
           "Pos_y: %d, "
           "height: %d, "
           "width: %d, "
           "\r\n",
           me->pos_x,
           me->pos_y,
           ((Rectangle *)me)->height,
           ((Rectangle *)me)->width);
}

// Method(s) - Overwrite move_to().
void rec_move_to(Shape *me, int32_t pos_x, int32_t pos_y)
{
    printf("Rectangle move from: "
           "[%d, %d] to [%d, %d]"
           "\r\n",
           me->pos_x,
           me->pos_y,
           pos_x,
           pos_y);
    me->pos_x = pos_x;
    me->pos_y = pos_y;
}

// Method(s) - rectangle_ctor
void rectangle_ctor(Rectangle *me, 
                    int32_t pos_x, 
                    int32_t pos_y, 
                    int32_t height, 
                    int32_t width)
{
    static const Vtbl recVtable = {
        .draw = rec_draw, 
        .move_to = rec_move_to,
    };
    ctor((Shape *)me, pos_x, pos_y);
    me->super.VtblPtr = &recVtable; // Overwrite the virtual table.
    me->height = height;
    me->width = width;
    printf("Calling Rectangle ctor...\r\n");
}

/****************** Class Circle *********************
    | attributes |
    | methods    |
*****************************************************/

// Attributes(s)
typedef struct Circle_t {
    Shape super;
    int32_t radius;
} Circle;

// Method(s) - Overwrite draw().
void circle_draw(Shape *me) 
{
    printf("Draw a circle. "
           "Pos_x: %d, "
           "Pos_y: %d, "
           "radius: %d, "
           "\r\n",
           me->pos_x,
           me->pos_y,
           ((Circle *)me)->radius);
}

// Method(s) - Overwrite move_to().
void circle_move_to(Shape *me, int32_t pos_x, int32_t pos_y)
{
    printf("Circle move from: "
           "[%d, %d] to [%d, %d]"
           "\r\n",
           me->pos_x,
           me->pos_y,
           pos_x,
           pos_y);
    me->pos_x = pos_x;
    me->pos_y = pos_y;
}

// Method(s) - circle_ctor
void circle_ctor(Circle *me, 
                 int32_t pos_x, 
                 int32_t pos_y, 
                 int32_t radius)
{
    static const Vtbl circleVtable = {
        .draw = circle_draw, 
        .move_to = circle_move_to,
    };
    ctor((Shape *)me, pos_x, pos_y);
    me->super.VtblPtr = &circleVtable; // Overwrite the virtual table.
    me->radius = radius;
    printf("Calling Circle ctor...\r\n");
}

/****************************************************/

void draw_any_shape(Shape *me)
{
    me->VtblPtr->draw(me);
}

void move_to_any_shape(Shape *me, int32_t pos_x, int32_t pos_y)
{
    me->VtblPtr->move_to(me, pos_x, pos_y);
}

int main(int argc, char **argv)
{
    Rectangle rec_0;
    Rectangle rec_1;
    Circle circle_0;
    Circle circle_1;
    Shape *shapeLst[4] = {
        [0] = (Shape *)&rec_0,
        [1] = (Shape *)&rec_1,
        [2] = (Shape *)&circle_0,
        [3] = (Shape *)&circle_1,
    }; 

    rectangle_ctor(&rec_0, 12, 12, 3, 4);
    rectangle_ctor(&rec_1, 15, 17, 6, 9);
    circle_ctor(&circle_0, 7, 8, 9);
    circle_ctor(&circle_1, 10, 23, 8);

    for (int8_t i; i < 4; i++) {
        draw_any_shape(shapeLst[i]);
        move_to_any_shape(shapeLst[i], 29, 29);
    }
    
    return 0;
}
