// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MARKETDATA_CRYPTO_H_
#define FLATBUFFERS_GENERATED_MARKETDATA_CRYPTO_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 3,
             "Non-compatible flatbuffers version included");

namespace crypto {

struct Trade;
struct TradeBuilder;

struct LevelUpdate;
struct LevelUpdateBuilder;

struct Message;
struct MessageBuilder;

struct MultiMessage;
struct MultiMessageBuilder;

enum MessageBody : uint8_t {
  MessageBody_NONE = 0,
  MessageBody_Trade = 1,
  MessageBody_LevelUpdate = 2,
  MessageBody_MIN = MessageBody_NONE,
  MessageBody_MAX = MessageBody_LevelUpdate
};

inline const MessageBody (&EnumValuesMessageBody())[3] {
  static const MessageBody values[] = {
    MessageBody_NONE,
    MessageBody_Trade,
    MessageBody_LevelUpdate
  };
  return values;
}

inline const char * const *EnumNamesMessageBody() {
  static const char * const names[4] = {
    "NONE",
    "Trade",
    "LevelUpdate",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessageBody(MessageBody e) {
  if (::flatbuffers::IsOutRange(e, MessageBody_NONE, MessageBody_LevelUpdate)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesMessageBody()[index];
}

template<typename T> struct MessageBodyTraits {
  static const MessageBody enum_value = MessageBody_NONE;
};

template<> struct MessageBodyTraits<crypto::Trade> {
  static const MessageBody enum_value = MessageBody_Trade;
};

template<> struct MessageBodyTraits<crypto::LevelUpdate> {
  static const MessageBody enum_value = MessageBody_LevelUpdate;
};

bool VerifyMessageBody(::flatbuffers::Verifier &verifier, const void *obj, MessageBody type);
bool VerifyMessageBodyVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<uint8_t> *types);

enum Side : uint8_t {
  Side_Buy = 0,
  Side_Sell = 1,
  Side_MIN = Side_Buy,
  Side_MAX = Side_Sell
};

inline const Side (&EnumValuesSide())[2] {
  static const Side values[] = {
    Side_Buy,
    Side_Sell
  };
  return values;
}

inline const char * const *EnumNamesSide() {
  static const char * const names[3] = {
    "Buy",
    "Sell",
    nullptr
  };
  return names;
}

inline const char *EnumNameSide(Side e) {
  if (::flatbuffers::IsOutRange(e, Side_Buy, Side_Sell)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesSide()[index];
}

struct Trade FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef TradeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PRICE = 4,
    VT_SIZE = 6
  };
  uint64_t price() const {
    return GetField<uint64_t>(VT_PRICE, 0);
  }
  uint32_t size() const {
    return GetField<uint32_t>(VT_SIZE, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_PRICE, 8) &&
           VerifyField<uint32_t>(verifier, VT_SIZE, 4) &&
           verifier.EndTable();
  }
};

struct TradeBuilder {
  typedef Trade Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_price(uint64_t price) {
    fbb_.AddElement<uint64_t>(Trade::VT_PRICE, price, 0);
  }
  void add_size(uint32_t size) {
    fbb_.AddElement<uint32_t>(Trade::VT_SIZE, size, 0);
  }
  explicit TradeBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Trade> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Trade>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Trade> CreateTrade(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t price = 0,
    uint32_t size = 0) {
  TradeBuilder builder_(_fbb);
  builder_.add_price(price);
  builder_.add_size(size);
  return builder_.Finish();
}

struct LevelUpdate FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef LevelUpdateBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PRICE = 4,
    VT_SIZE = 6,
    VT_FLAGS = 8,
    VT_SIDE = 10
  };
  uint64_t price() const {
    return GetField<uint64_t>(VT_PRICE, 0);
  }
  uint32_t size() const {
    return GetField<uint32_t>(VT_SIZE, 0);
  }
  uint8_t flags() const {
    return GetField<uint8_t>(VT_FLAGS, 0);
  }
  crypto::Side side() const {
    return static_cast<crypto::Side>(GetField<uint8_t>(VT_SIDE, 0));
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_PRICE, 8) &&
           VerifyField<uint32_t>(verifier, VT_SIZE, 4) &&
           VerifyField<uint8_t>(verifier, VT_FLAGS, 1) &&
           VerifyField<uint8_t>(verifier, VT_SIDE, 1) &&
           verifier.EndTable();
  }
};

struct LevelUpdateBuilder {
  typedef LevelUpdate Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_price(uint64_t price) {
    fbb_.AddElement<uint64_t>(LevelUpdate::VT_PRICE, price, 0);
  }
  void add_size(uint32_t size) {
    fbb_.AddElement<uint32_t>(LevelUpdate::VT_SIZE, size, 0);
  }
  void add_flags(uint8_t flags) {
    fbb_.AddElement<uint8_t>(LevelUpdate::VT_FLAGS, flags, 0);
  }
  void add_side(crypto::Side side) {
    fbb_.AddElement<uint8_t>(LevelUpdate::VT_SIDE, static_cast<uint8_t>(side), 0);
  }
  explicit LevelUpdateBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<LevelUpdate> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<LevelUpdate>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<LevelUpdate> CreateLevelUpdate(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t price = 0,
    uint32_t size = 0,
    uint8_t flags = 0,
    crypto::Side side = crypto::Side_Buy) {
  LevelUpdateBuilder builder_(_fbb);
  builder_.add_price(price);
  builder_.add_size(size);
  builder_.add_side(side);
  builder_.add_flags(flags);
  return builder_.Finish();
}

struct Message FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MessageBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TS_NANOS = 4,
    VT_SYMBOL = 6,
    VT_BODY_TYPE = 8,
    VT_BODY = 10
  };
  int64_t ts_nanos() const {
    return GetField<int64_t>(VT_TS_NANOS, 0);
  }
  const ::flatbuffers::String *symbol() const {
    return GetPointer<const ::flatbuffers::String *>(VT_SYMBOL);
  }
  crypto::MessageBody body_type() const {
    return static_cast<crypto::MessageBody>(GetField<uint8_t>(VT_BODY_TYPE, 0));
  }
  const void *body() const {
    return GetPointer<const void *>(VT_BODY);
  }
  template<typename T> const T *body_as() const;
  const crypto::Trade *body_as_Trade() const {
    return body_type() == crypto::MessageBody_Trade ? static_cast<const crypto::Trade *>(body()) : nullptr;
  }
  const crypto::LevelUpdate *body_as_LevelUpdate() const {
    return body_type() == crypto::MessageBody_LevelUpdate ? static_cast<const crypto::LevelUpdate *>(body()) : nullptr;
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_TS_NANOS, 8) &&
           VerifyOffset(verifier, VT_SYMBOL) &&
           verifier.VerifyString(symbol()) &&
           VerifyField<uint8_t>(verifier, VT_BODY_TYPE, 1) &&
           VerifyOffset(verifier, VT_BODY) &&
           VerifyMessageBody(verifier, body(), body_type()) &&
           verifier.EndTable();
  }
};

template<> inline const crypto::Trade *Message::body_as<crypto::Trade>() const {
  return body_as_Trade();
}

template<> inline const crypto::LevelUpdate *Message::body_as<crypto::LevelUpdate>() const {
  return body_as_LevelUpdate();
}

struct MessageBuilder {
  typedef Message Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_ts_nanos(int64_t ts_nanos) {
    fbb_.AddElement<int64_t>(Message::VT_TS_NANOS, ts_nanos, 0);
  }
  void add_symbol(::flatbuffers::Offset<::flatbuffers::String> symbol) {
    fbb_.AddOffset(Message::VT_SYMBOL, symbol);
  }
  void add_body_type(crypto::MessageBody body_type) {
    fbb_.AddElement<uint8_t>(Message::VT_BODY_TYPE, static_cast<uint8_t>(body_type), 0);
  }
  void add_body(::flatbuffers::Offset<void> body) {
    fbb_.AddOffset(Message::VT_BODY, body);
  }
  explicit MessageBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Message>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Message> CreateMessage(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int64_t ts_nanos = 0,
    ::flatbuffers::Offset<::flatbuffers::String> symbol = 0,
    crypto::MessageBody body_type = crypto::MessageBody_NONE,
    ::flatbuffers::Offset<void> body = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_ts_nanos(ts_nanos);
  builder_.add_body(body);
  builder_.add_symbol(symbol);
  builder_.add_body_type(body_type);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Message> CreateMessageDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int64_t ts_nanos = 0,
    const char *symbol = nullptr,
    crypto::MessageBody body_type = crypto::MessageBody_NONE,
    ::flatbuffers::Offset<void> body = 0) {
  auto symbol__ = symbol ? _fbb.CreateString(symbol) : 0;
  return crypto::CreateMessage(
      _fbb,
      ts_nanos,
      symbol__,
      body_type,
      body);
}

struct MultiMessage FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MultiMessageBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SEQ_NO = 4,
    VT_MESSAGES = 6
  };
  uint64_t seq_no() const {
    return GetField<uint64_t>(VT_SEQ_NO, 0);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<crypto::Message>> *messages() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<crypto::Message>> *>(VT_MESSAGES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_SEQ_NO, 8) &&
           VerifyOffset(verifier, VT_MESSAGES) &&
           verifier.VerifyVector(messages()) &&
           verifier.VerifyVectorOfTables(messages()) &&
           verifier.EndTable();
  }
};

struct MultiMessageBuilder {
  typedef MultiMessage Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_seq_no(uint64_t seq_no) {
    fbb_.AddElement<uint64_t>(MultiMessage::VT_SEQ_NO, seq_no, 0);
  }
  void add_messages(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<crypto::Message>>> messages) {
    fbb_.AddOffset(MultiMessage::VT_MESSAGES, messages);
  }
  explicit MultiMessageBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<MultiMessage> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<MultiMessage>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<MultiMessage> CreateMultiMessage(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t seq_no = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<crypto::Message>>> messages = 0) {
  MultiMessageBuilder builder_(_fbb);
  builder_.add_seq_no(seq_no);
  builder_.add_messages(messages);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<MultiMessage> CreateMultiMessageDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t seq_no = 0,
    const std::vector<::flatbuffers::Offset<crypto::Message>> *messages = nullptr) {
  auto messages__ = messages ? _fbb.CreateVector<::flatbuffers::Offset<crypto::Message>>(*messages) : 0;
  return crypto::CreateMultiMessage(
      _fbb,
      seq_no,
      messages__);
}

inline bool VerifyMessageBody(::flatbuffers::Verifier &verifier, const void *obj, MessageBody type) {
  switch (type) {
    case MessageBody_NONE: {
      return true;
    }
    case MessageBody_Trade: {
      auto ptr = reinterpret_cast<const crypto::Trade *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_LevelUpdate: {
      auto ptr = reinterpret_cast<const crypto::LevelUpdate *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyMessageBodyVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (::flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessageBody(
        verifier,  values->Get(i), types->GetEnum<MessageBody>(i))) {
      return false;
    }
  }
  return true;
}

inline const crypto::MultiMessage *GetMultiMessage(const void *buf) {
  return ::flatbuffers::GetRoot<crypto::MultiMessage>(buf);
}

inline const crypto::MultiMessage *GetSizePrefixedMultiMessage(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<crypto::MultiMessage>(buf);
}

inline bool VerifyMultiMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<crypto::MultiMessage>(nullptr);
}

inline bool VerifySizePrefixedMultiMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<crypto::MultiMessage>(nullptr);
}

inline void FinishMultiMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<crypto::MultiMessage> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedMultiMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<crypto::MultiMessage> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace crypto

#endif  // FLATBUFFERS_GENERATED_MARKETDATA_CRYPTO_H_
