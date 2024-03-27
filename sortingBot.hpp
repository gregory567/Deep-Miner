#ifndef SORTINGBOT_HPP_INCLUDED
#define SORTINGBOT_HPP_INCLUDED

class sortingBot: public Robot{
    public:
        sortingBot(std::string name);
        virtual ~sortingBot();

        void extract(Mine& m, const int x, const int y) override;


    protected:

    private:


};

#endif // SORTINGBOT_HPP_INCLUDED
