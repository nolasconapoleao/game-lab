//
// Created by nolasco on 27/06/20.
//

#pragma once

// clang-format off

enum Menu : char {
  TR_MENU = 'm',
    TR_SAVE = 's',
    TR_TUTORIAL = 't',
  TR_SKIP_TURN = 'e',
  TR_BATTLE = 'a',
    TR_BATTLE_CHARACTER = 'c',
    TR_BATTLE_BUILDING = 'b',
    TR_BATTLE_STRUCTURE = 's',
  TR_PICKUP = 'p',
  TR_INVENTORY = 'i',
    TR_ITEM_DROP = 'd',
    TR_ITEM_USE = 'u',
  TR_PARTY = 't',
    TR_PARTY_CREATE = 'c',
    TR_PARTY_DISBAND = 'd',
    TR_PARTY_TRADE = 't',
    TR_PARTY_KICK = 'k',
    TR_PARTY_INVITE = 'i',
  TR_SHOP = 's',          // needs shop and shopkeeper
    TR_SHOP_BUY = 'b',
    TR_SHOP_SELL = 's',
  TR_QUEST = 'q',
    TR_QUEST_READ = 'r',
    TR_QUEST_ABANDON = 'd',
    TR_QUEST_FINISH = 'f',
  TR_TRAVEL = 'w',
  TR_TERMINATE = 'x',

  // #### Special option ####
  TR_SUMMON = 'b',        // mage only
  TR_PICKPOCKET = 'o',    // thief only
  TR_POSSESS = 'g',       // mage only
  TR_READ_BOOK = 'r',     // needs bookshelf
  TR_CALL = 'c',          // needs phonebooth
    TR_REINFORCEMENT = 'r',
    TR_TAUNT_ENEMY = 't',

};
// clang-format on
