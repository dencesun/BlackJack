//
//  blackjack.hpp
//  Blackjack
//
//  Created by dencesun on 30/11/2017.
//  Copyright © 2017 Sun. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Card {
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    friend ostream& operator<<(ostream&, const Card& aCard);
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    // 返回牌的点值
    int GetValue() const;
    // 翻牌。正面的牌将朝下，反面的牌将朝上
    void Flip();

private:

    // 牌的大小, rank是表示所有13个等级的枚举类型
    rank m_Rank;
    // 牌的花色，suit是表示4种可能花色的枚举类型
    suit m_Suit;
    // 指示扑克牌是否正面朝上，影响牌的显示以及它的点数
    bool m_IsFaceUp;

};

class Hand {
public:
    Hand();
    virtual ~Hand();
    // 向所持偏重添加一张牌。在向量m_Cards中添加一个Card指针
    void Add(Card* pCard);
    // 清空所有持有的牌。移除m_Cards中的所有指针，删除堆中相关的Card对象
    void Clear();
    // 返回所持牌的点数总和
    int GetTotal() const;

protected:
    // 扑克牌的集合。 它存储Card对象的指针。
    vector<Card*> m_Cards;
};

class GenericPlayer : public Hand {
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();
    // 指示玩家是否跟牌，是纯虚函数
    virtual bool IsHitting() const = 0;
    // 指示玩家是否失败
    bool IsBusted() const;
    // 宣布玩家失败
    void Bust() const;

protected:
    // 玩家的姓名
    string m_Name;

};

class Player : public GenericPlayer{
public:
    Player(const string& name = "");
    virtual ~Player();
    // 指示人类玩家是否跟牌
    virtual bool IsHitting() const;
    // 宣布人类玩家获胜
    void Win() const;
    // 宣布人类玩家失败
    void Lose() const;
    // 宣布人类玩家与庄家打平
    void Push() const;

};

class House : public GenericPlayer {
public:
    House(const string& name = "House");
    virtual ~House();
    // 指示庄家是否跟牌
    virtual bool IsHitting() const;
    // 翻开第一张牌
    void FlipFirstCard();

};

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    // 生成包含52张牌的标准牌堆
    void Populate();
    // 洗牌
    void Shuffle();
    // 发牌
    void Deal(Hand& aHand);
    // 只要玩家跟牌， 就向玩家发牌
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

class Game {
public:
    Game(const vector<string>& names);
    ~Game();
    // 进行一轮Blackjack游戏
    void Play();
private:
    // 牌堆
    Deck m_Deck;
    // 赌场，庄家
    House m_House;
    // 人类玩家的集合，是Player对象的向量
    vector<Player> m_Players;
};

#endif /* blackjack_hpp */














































