// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_lite_support/cc/task/vision/proto/bounding_box.proto

#include "tensorflow_lite_support/cc/task/vision/proto/bounding_box.pb.h"

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
namespace vision {
        template <typename>
PROTOBUF_CONSTEXPR BoundingBox::BoundingBox(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_._has_bits_)*/ {},
      /*decltype(_impl_._cached_size_)*/ {},
      /*decltype(_impl_.origin_x_)*/ 0,
      /*decltype(_impl_.origin_y_)*/ 0,
      /*decltype(_impl_.width_)*/ 0,
      /*decltype(_impl_.height_)*/ 0,
    } {}
struct BoundingBoxDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BoundingBoxDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BoundingBoxDefaultTypeInternal() {}
  union {
    BoundingBox _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BoundingBoxDefaultTypeInternal _BoundingBox_default_instance_;
}  // namespace vision
}  // namespace task
}  // namespace tflite
static ::_pb::Metadata file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto = nullptr;
const ::uint32_t TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _impl_.origin_x_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _impl_.origin_y_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _impl_.width_),
    PROTOBUF_FIELD_OFFSET(::tflite::task::vision::BoundingBox, _impl_.height_),
    0,
    1,
    2,
    3,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 12, -1, sizeof(::tflite::task::vision::BoundingBox)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::tflite::task::vision::_BoundingBox_default_instance_._instance,
};
const char descriptor_table_protodef_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\?tensorflow_lite_support/cc/task/vision"
    "/proto/bounding_box.proto\022\022tflite.task.v"
    "ision\"P\n\013BoundingBox\022\020\n\010origin_x\030\001 \001(\005\022\020"
    "\n\010origin_y\030\002 \001(\005\022\r\n\005width\030\003 \001(\005\022\016\n\006heigh"
    "t\030\004 \001(\005"
};
static ::absl::once_flag descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto = {
    false,
    false,
    167,
    descriptor_table_protodef_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto,
    "tensorflow_lite_support/cc/task/vision/proto/bounding_box.proto",
    &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto::offsets,
    file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto,
    file_level_enum_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto,
    file_level_service_descriptors_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto_getter() {
  return &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto(&descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto);
namespace tflite {
namespace task {
namespace vision {
// ===================================================================

class BoundingBox::_Internal {
 public:
  using HasBits = decltype(std::declval<BoundingBox>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_._has_bits_);
  static void set_has_origin_x(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_origin_y(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_width(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_height(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
};

BoundingBox::BoundingBox(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tflite.task.vision.BoundingBox)
}
BoundingBox::BoundingBox(const BoundingBox& from)
    : ::google::protobuf::Message(), _impl_(from._impl_) {
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:tflite.task.vision.BoundingBox)
}
inline void BoundingBox::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){},
      /*decltype(_impl_._cached_size_)*/ {},
      decltype(_impl_.origin_x_){0},
      decltype(_impl_.origin_y_){0},
      decltype(_impl_.width_){0},
      decltype(_impl_.height_){0},
  };
}
BoundingBox::~BoundingBox() {
  // @@protoc_insertion_point(destructor:tflite.task.vision.BoundingBox)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void BoundingBox::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
}
void BoundingBox::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void BoundingBox::Clear() {
// @@protoc_insertion_point(message_clear_start:tflite.task.vision.BoundingBox)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    ::memset(&_impl_.origin_x_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.height_) -
        reinterpret_cast<char*>(&_impl_.origin_x_)) + sizeof(_impl_.height_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* BoundingBox::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 0, 2> BoundingBox::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_._has_bits_),
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_BoundingBox_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // optional int32 height = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(BoundingBox, _impl_.height_), 3>(),
     {32, 3, 0, PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.height_)}},
    // optional int32 origin_x = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(BoundingBox, _impl_.origin_x_), 0>(),
     {8, 0, 0, PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.origin_x_)}},
    // optional int32 origin_y = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(BoundingBox, _impl_.origin_y_), 1>(),
     {16, 1, 0, PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.origin_y_)}},
    // optional int32 width = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(BoundingBox, _impl_.width_), 2>(),
     {24, 2, 0, PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.width_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional int32 origin_x = 1;
    {PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.origin_x_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 origin_y = 2;
    {PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.origin_y_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 width = 3;
    {PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.width_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 height = 4;
    {PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.height_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* BoundingBox::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tflite.task.vision.BoundingBox)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional int32 origin_x = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_origin_x(), target);
  }

  // optional int32 origin_y = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_origin_y(), target);
  }

  // optional int32 width = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<3>(
            stream, this->_internal_width(), target);
  }

  // optional int32 height = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<4>(
            stream, this->_internal_height(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tflite.task.vision.BoundingBox)
  return target;
}

::size_t BoundingBox::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tflite.task.vision.BoundingBox)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional int32 origin_x = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_origin_x());
    }

    // optional int32 origin_y = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_origin_y());
    }

    // optional int32 width = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_width());
    }

    // optional int32 height = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_height());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData BoundingBox::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    BoundingBox::MergeImpl
};
const ::google::protobuf::Message::ClassData*BoundingBox::GetClassData() const { return &_class_data_; }


void BoundingBox::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<BoundingBox*>(&to_msg);
  auto& from = static_cast<const BoundingBox&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tflite.task.vision.BoundingBox)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_impl_.origin_x_ = from._impl_.origin_x_;
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.origin_y_ = from._impl_.origin_y_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.width_ = from._impl_.width_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.height_ = from._impl_.height_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void BoundingBox::CopyFrom(const BoundingBox& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tflite.task.vision.BoundingBox)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool BoundingBox::IsInitialized() const {
  return true;
}

void BoundingBox::InternalSwap(BoundingBox* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.height_)
      + sizeof(BoundingBox::_impl_.height_)
      - PROTOBUF_FIELD_OFFSET(BoundingBox, _impl_.origin_x_)>(
          reinterpret_cast<char*>(&_impl_.origin_x_),
          reinterpret_cast<char*>(&other->_impl_.origin_x_));
}

::google::protobuf::Metadata BoundingBox::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto_getter, &descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto_once,
      file_level_metadata_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fbounding_5fbox_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace vision
}  // namespace task
}  // namespace tflite
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"