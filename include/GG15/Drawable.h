#ifndef DRAWABLE_H
#define DRAWABLE_H


namespace GG15
{
    struct pixel_vector
    {
        int x = 0;
        int y = 0;
    };

    class Drawable
    {
        protected:
        int posX = 0;
        int posY = 0;

        int width = 0;
        int height = 0;

        public:

        Drawable();
        virtual ~Drawable();

        void set_position(int x, int y);
        pixel_vector get_position();

    };
}


#endif // DRAWABLE_H
