#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
    public:
        Monster(hP) hitPoints{hP};
        virtual ~Monster();
        void attack(int hP){};

    protected:
        int hitPoints;

    private:
};

#endif // MONSTER_H
