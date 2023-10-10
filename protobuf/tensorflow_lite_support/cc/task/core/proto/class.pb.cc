// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_lite_support/cc/task/core/proto/class.proto

#include "tensorflow_lite_support/cc/task/core/proto/class.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace tflite {
namespace task {
namespace core {
        template <typename>
PROTOBUF_CONSTEXPR Class::Class(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_._has_bits_)*/ {},
      /*decltype(_impl_._cached_size_)*/ {},
      /*decltype(_impl_.display_name_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_.class_name_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_.index_)*/ 0,
      /*decltype(_impl_.score_)*/ 0,
    } {}
struct ClassDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ClassDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ClassDefaultTypeInternal() {}
  union {
    Class _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ClassDefaultTypeInternal _Class_default_instance_;
}  // namespace core
}  // namespace task
}  // namespace tflite
static ::_pb::Metadata file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto = nullptr;
const ::uint32_t TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _impl_.index_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _impl_.score_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _impl_.display_name_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::core::Class, _impl_.class_name_),
    2,
    3,
    0,
    1,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 12, -1, sizeof(::tflite::task::core::Class)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::tflite::task::core::_Class_default_instance_._instance,
};
const char descriptor_table_protodef_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n6tensorflow_lite_support/cc/task/core/p"
    "roto/class.proto\022\020tflite.task.core\"O\n\005Cl"
    "ass\022\r\n\005index\030\001 \001(\005\022\r\n\005score\030\002 \001(\002\022\024\n\014dis"
    "play_name\030\003 \001(\t\022\022\n\nclass_name\030\004 \001(\t"
};
static ::absl::once_flag descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto = {
    false,
    false,
    155,
    descriptor_table_protodef_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto,
    "tensorflow_lite_support/cc/task/core/proto/class.proto",
    &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto::offsets,
    file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto,
    file_level_enum_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto,
    file_level_service_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto_getter() {
  return &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto(&descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto);
namespace tflite {
namespace task {
namespace core {
// ===================================================================

class Class::_Internal {
 public:
  using HasBits = decltype(std::declval<Class>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(Class, _impl_._has_bits_);
  static void set_has_index(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_score(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_display_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_class_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

Class::Class(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tflite.task.core.Class)
}
Class::Class(const Class& from) : ::google::protobuf::Message() {
  Class* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_},
      /*decltype(_impl_._cached_size_)*/ {},
      decltype(_impl_.display_name_){},
      decltype(_impl_.class_name_){},
      decltype(_impl_.index_){},
      decltype(_impl_.score_){},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.display_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.display_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_impl_.display_name_.Set(from._internal_display_name(), _this->GetArenaForAllocation());
  }
  _impl_.class_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.class_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if ((from._impl_._has_bits_[0] & 0x00000002u) != 0) {
    _this->_impl_.class_name_.Set(from._internal_class_name(), _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.index_, &from._impl_.index_,
    static_cast<::size_t>(reinterpret_cast<char*>(&_impl_.score_) -
    reinterpret_cast<char*>(&_impl_.index_)) + sizeof(_impl_.score_));

  // @@protoc_insertion_point(copy_constructor:tflite.task.core.Class)
}
inline void Class::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){},
      /*decltype(_impl_._cached_size_)*/ {},
      decltype(_impl_.display_name_){},
      decltype(_impl_.class_name_){},
      decltype(_impl_.index_){0},
      decltype(_impl_.score_){0},
  };
  _impl_.display_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.display_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.class_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.class_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
Class::~Class() {
  // @@protoc_insertion_point(destructor:tflite.task.core.Class)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Class::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.display_name_.Destroy();
  _impl_.class_name_.Destroy();
}
void Class::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void Class::Clear() {
// @@protoc_insertion_point(message_clear_start:tflite.task.core.Class)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.display_name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.class_name_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x0000000cu) {
    ::memset(&_impl_.index_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.score_) -
        reinterpret_cast<char*>(&_impl_.index_)) + sizeof(_impl_.score_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Class::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 53, 2> Class::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Class, _impl_._has_bits_),
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Class_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // optional string class_name = 4;
    {::_pbi::TcParser::FastSS1,
     {34, 1, 0, PROTOBUF_FIELD_OFFSET(Class, _impl_.class_name_)}},
    // optional int32 index = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Class, _impl_.index_), 2>(),
     {8, 2, 0, PROTOBUF_FIELD_OFFSET(Class, _impl_.index_)}},
    // optional float score = 2;
    {::_pbi::TcParser::FastF32S1,
     {21, 3, 0, PROTOBUF_FIELD_OFFSET(Class, _impl_.score_)}},
    // optional string display_name = 3;
    {::_pbi::TcParser::FastSS1,
     {26, 0, 0, PROTOBUF_FIELD_OFFSET(Class, _impl_.display_name_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional int32 index = 1;
    {PROTOBUF_FIELD_OFFSET(Class, _impl_.index_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional float score = 2;
    {PROTOBUF_FIELD_OFFSET(Class, _impl_.score_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kFloat)},
    // optional string display_name = 3;
    {PROTOBUF_FIELD_OFFSET(Class, _impl_.display_name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional string class_name = 4;
    {PROTOBUF_FIELD_OFFSET(Class, _impl_.class_name_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\26\0\0\14\12\0\0\0"
    "tflite.task.core.Class"
    "display_name"
    "class_name"
  }},
};

::uint8_t* Class::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tflite.task.core.Class)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional int32 index = 1;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_index(), target);
  }

  // optional float score = 2;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        2, this->_internal_score(), target);
  }

  // optional string display_name = 3;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_display_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "tflite.task.core.Class.display_name");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // optional string class_name = 4;
  if (cached_has_bits & 0x00000002u) {
    const std::string& _s = this->_internal_class_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "tflite.task.core.Class.class_name");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tflite.task.core.Class)
  return target;
}

::size_t Class::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tflite.task.core.Class)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional string display_name = 3;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_display_name());
    }

    // optional string class_name = 4;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_class_name());
    }

    // optional int32 index = 1;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_index());
    }

    // optional float score = 2;
    if (cached_has_bits & 0x00000008u) {
      total_size += 5;
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Class::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    Class::MergeImpl
};
const ::google::protobuf::Message::ClassData*Class::GetClassData() const { return &_class_data_; }


void Class::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Class*>(&to_msg);
  auto& from = static_cast<const Class&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tflite.task.core.Class)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_display_name(from._internal_display_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_class_name(from._internal_class_name());
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.index_ = from._impl_.index_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.score_ = from._impl_.score_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Class::CopyFrom(const Class& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tflite.task.core.Class)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Class::IsInitialized() const {
  return true;
}

void Class::InternalSwap(Class* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.display_name_, lhs_arena,
                                       &other->_impl_.display_name_, rhs_arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.class_name_, lhs_arena,
                                       &other->_impl_.class_name_, rhs_arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Class, _impl_.score_)
      + sizeof(Class::_impl_.score_)
      - PROTOBUF_FIELD_OFFSET(Class, _impl_.index_)>(
          reinterpret_cast<char*>(&_impl_.index_),
          reinterpret_cast<char*>(&other->_impl_.index_));
}

::google::protobuf::Metadata Class::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto_getter, &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto_once,
      file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fcore_2fproto_2fclass_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace core
}  // namespace task
}  // namespace tflite
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"