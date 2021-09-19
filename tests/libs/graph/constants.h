//
// Created by nolasco on 04/06/20.
//

#pragma once

using NetworkLink = std::pair<uint8_t, uint8_t>;

namespace constants {

constexpr uint8_t brotherhood = 10u;
constexpr uint8_t friendship = 5u;
constexpr uint8_t acquaintance = 1u;

constexpr uint8_t person1Id = 1u;
constexpr uint8_t person2Id = 2u;
constexpr uint8_t person3Id = 3u;
constexpr uint8_t person4Id = 4u;

constexpr auto person1Name = "Nolasco";
constexpr auto person2Name = "Cesar";
constexpr auto person3Name = "Ferdinando";
constexpr auto person4Name = "Julius";

NetworkLink invalidLink{person1Id, person1Id};
NetworkLink invalidLink2{person2Id, person2Id};
NetworkLink invalidLink3{person3Id, person3Id};

NetworkLink validLink12{person1Id, person2Id};
NetworkLink validLink21{person2Id, person1Id};
NetworkLink validLink13{person1Id, person3Id};
NetworkLink validLink31{person3Id, person1Id};
NetworkLink validLink23{person2Id, person3Id};
NetworkLink validLink32{person3Id, person2Id};
NetworkLink validLink14{person1Id, person4Id};
NetworkLink validLink41{person4Id, person1Id};

} // namespace constants
