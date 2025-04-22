#include <eosio/eosio.hpp>

class [[eosio::contract("didregistry")]] didregistry : public eosio::contract {
public:
   using contract::contract;

   struct [[eosio::table]] record {
      eosio::name owner;
      std::string doc;
      uint64_t primary_key() const { return owner.value; }
   };

   using table = eosio::multi_index<"dids"_n, record>;

   [[eosio::action]]
   void regdid(eosio::name owner, std::string doc) {
      require_auth(owner);
      table t(get_self(), get_self().value);
      auto itr = t.find(owner.value);
      if (itr == t.end())
         t.emplace(owner, [&](auto& r){ r.owner = owner; r.doc = doc; });
      else
         t.modify(itr, owner, [&](auto& r){ r.doc = doc; });
   }
};
