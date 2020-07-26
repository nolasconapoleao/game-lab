//
// Created by nolasco on 27/06/20.
//

#pragma once

enum class ActionType {
  SKIP_TURN = 'e',
  MENU = 'm',
  MENU_SAVE = 's',
  MENU_TUTORIAL = 't',
  MENU_TERMINATE = 'x',
  ATTACK = 'a',
  ATTACK_CHARACTER = 'c',
  ATTACK_BUILDING = 'b',
  ATTACK_STRUCTURE = 's',
  INVENTORY = 'i',
  INVENTORY_PICKUP = 'p',
  INVENTORY_DROP = 'd',
  INVENTORY_USE = 'u',
  PARTY = 't',
  PARTY_CREATE = 'c',
  PARTY_DISBAND = 'd',
  PARTY_TRADE = 't',
  PARTY_KICK = 'k',
  PARTY_INVITE = 'i',
  SHOP = 's',
  SHOP_BUY = 'b',
  SHOP_SELL = 's',
  QUEST = 'q',
  QUEST_ABANDON = 'd',
  QUEST_FINISH = 'f',
  TRAVEL = 'w',

  SPECIAL = '*',
  SPECIAL_SUMMON = 'b',
  SPECIAL_PICKPOCKET = 'o',
  SPECIAL_POSSESS = 'g',
  SPECIAL_READ = 'r',
  SPECIAL_CALL = 'c',
  SPECIAL_CALL_REINFORCEMENT = 'r',
  SPECIAL_CALL_ENEMY = 't',
};
