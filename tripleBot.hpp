#ifndef TRIPLEBOT_HPP_INCLUDED
#define TRIPLEBOT_HPP_INCLUDED

class tripleBot: public Robot{
    public:
        tripleBot(std::string name);
        virtual ~tripleBot();

        void extract(Mine& m, const int x, const int y) override;


    protected:

    private:


};


#endif // TRIPLEBOT_HPP_INCLUDED
