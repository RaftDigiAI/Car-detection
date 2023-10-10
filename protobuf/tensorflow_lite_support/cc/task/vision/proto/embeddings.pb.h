// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_lite_support/cc/task/vision/proto/embeddings.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4024000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4024003 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto;
namespace tflite {
namespace task {
namespace vision {
class Embedding;
struct EmbeddingDefaultTypeInternal;
extern EmbeddingDefaultTypeInternal _Embedding_default_instance_;
class EmbeddingResult;
struct EmbeddingResultDefaultTypeInternal;
extern EmbeddingResultDefaultTypeInternal _EmbeddingResult_default_instance_;
class FeatureVector;
struct FeatureVectorDefaultTypeInternal;
extern FeatureVectorDefaultTypeInternal _FeatureVector_default_instance_;
}  // namespace vision
}  // namespace task
}  // namespace tflite
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tflite {
namespace task {
namespace vision {

// ===================================================================


// -------------------------------------------------------------------

class FeatureVector final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tflite.task.vision.FeatureVector) */ {
 public:
  inline FeatureVector() : FeatureVector(nullptr) {}
  ~FeatureVector() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR FeatureVector(::google::protobuf::internal::ConstantInitialized);

  FeatureVector(const FeatureVector& from);
  FeatureVector(FeatureVector&& from) noexcept
    : FeatureVector() {
    *this = ::std::move(from);
  }

  inline FeatureVector& operator=(const FeatureVector& from) {
    CopyFrom(from);
    return *this;
  }
  inline FeatureVector& operator=(FeatureVector&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FeatureVector& default_instance() {
    return *internal_default_instance();
  }
  static inline const FeatureVector* internal_default_instance() {
    return reinterpret_cast<const FeatureVector*>(
               &_FeatureVector_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FeatureVector& a, FeatureVector& b) {
    a.Swap(&b);
  }
  inline void Swap(FeatureVector* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FeatureVector* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FeatureVector* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FeatureVector>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const FeatureVector& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const FeatureVector& from) {
    FeatureVector::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FeatureVector* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tflite.task.vision.FeatureVector";
  }
  protected:
  explicit FeatureVector(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFloatFieldNumber = 1,
    kValueStringFieldNumber = 2,
  };
  // repeated float value_float = 1 [packed = true];
  int value_float_size() const;
  private:
  int _internal_value_float_size() const;

  public:
  void clear_value_float() ;
  float value_float(int index) const;
  void set_value_float(int index, float value);
  void add_value_float(float value);
  const ::google::protobuf::RepeatedField<float>& value_float() const;
  ::google::protobuf::RepeatedField<float>* mutable_value_float();

  private:
  const ::google::protobuf::RepeatedField<float>& _internal_value_float() const;
  ::google::protobuf::RepeatedField<float>* _internal_mutable_value_float();

  public:
  // optional bytes value_string = 2;
  bool has_value_string() const;
  void clear_value_string() ;
  const std::string& value_string() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_value_string(Arg_&& arg, Args_... args);
  std::string* mutable_value_string();
  PROTOBUF_NODISCARD std::string* release_value_string();
  void set_allocated_value_string(std::string* ptr);

  private:
  const std::string& _internal_value_string() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_value_string(
      const std::string& value);
  std::string* _internal_mutable_value_string();

  public:
  // @@protoc_insertion_point(class_scope:tflite.task.vision.FeatureVector)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<1, 2, 0, 0, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::RepeatedField<float> value_float_;
    ::google::protobuf::internal::ArenaStringPtr value_string_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto;
};// -------------------------------------------------------------------

class Embedding final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tflite.task.vision.Embedding) */ {
 public:
  inline Embedding() : Embedding(nullptr) {}
  ~Embedding() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Embedding(::google::protobuf::internal::ConstantInitialized);

  Embedding(const Embedding& from);
  Embedding(Embedding&& from) noexcept
    : Embedding() {
    *this = ::std::move(from);
  }

  inline Embedding& operator=(const Embedding& from) {
    CopyFrom(from);
    return *this;
  }
  inline Embedding& operator=(Embedding&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Embedding& default_instance() {
    return *internal_default_instance();
  }
  static inline const Embedding* internal_default_instance() {
    return reinterpret_cast<const Embedding*>(
               &_Embedding_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Embedding& a, Embedding& b) {
    a.Swap(&b);
  }
  inline void Swap(Embedding* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Embedding* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Embedding* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Embedding>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Embedding& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Embedding& from) {
    Embedding::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Embedding* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tflite.task.vision.Embedding";
  }
  protected:
  explicit Embedding(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFeatureVectorFieldNumber = 1,
    kOutputIndexFieldNumber = 2,
  };
  // optional .tflite.task.vision.FeatureVector feature_vector = 1;
  bool has_feature_vector() const;
  void clear_feature_vector() ;
  const ::tflite::task::vision::FeatureVector& feature_vector() const;
  PROTOBUF_NODISCARD ::tflite::task::vision::FeatureVector* release_feature_vector();
  ::tflite::task::vision::FeatureVector* mutable_feature_vector();
  void set_allocated_feature_vector(::tflite::task::vision::FeatureVector* value);
  void unsafe_arena_set_allocated_feature_vector(::tflite::task::vision::FeatureVector* value);
  ::tflite::task::vision::FeatureVector* unsafe_arena_release_feature_vector();

  private:
  const ::tflite::task::vision::FeatureVector& _internal_feature_vector() const;
  ::tflite::task::vision::FeatureVector* _internal_mutable_feature_vector();

  public:
  // optional int32 output_index = 2;
  bool has_output_index() const;
  void clear_output_index() ;
  ::int32_t output_index() const;
  void set_output_index(::int32_t value);

  private:
  ::int32_t _internal_output_index() const;
  void _internal_set_output_index(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:tflite.task.vision.Embedding)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<1, 2, 1, 0, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::tflite::task::vision::FeatureVector* feature_vector_;
    ::int32_t output_index_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto;
};// -------------------------------------------------------------------

class EmbeddingResult final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tflite.task.vision.EmbeddingResult) */ {
 public:
  inline EmbeddingResult() : EmbeddingResult(nullptr) {}
  ~EmbeddingResult() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR EmbeddingResult(::google::protobuf::internal::ConstantInitialized);

  EmbeddingResult(const EmbeddingResult& from);
  EmbeddingResult(EmbeddingResult&& from) noexcept
    : EmbeddingResult() {
    *this = ::std::move(from);
  }

  inline EmbeddingResult& operator=(const EmbeddingResult& from) {
    CopyFrom(from);
    return *this;
  }
  inline EmbeddingResult& operator=(EmbeddingResult&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const EmbeddingResult& default_instance() {
    return *internal_default_instance();
  }
  static inline const EmbeddingResult* internal_default_instance() {
    return reinterpret_cast<const EmbeddingResult*>(
               &_EmbeddingResult_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(EmbeddingResult& a, EmbeddingResult& b) {
    a.Swap(&b);
  }
  inline void Swap(EmbeddingResult* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EmbeddingResult* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  EmbeddingResult* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<EmbeddingResult>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const EmbeddingResult& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const EmbeddingResult& from) {
    EmbeddingResult::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EmbeddingResult* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tflite.task.vision.EmbeddingResult";
  }
  protected:
  explicit EmbeddingResult(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEmbeddingsFieldNumber = 1,
  };
  // repeated .tflite.task.vision.Embedding embeddings = 1;
  int embeddings_size() const;
  private:
  int _internal_embeddings_size() const;

  public:
  void clear_embeddings() ;
  ::tflite::task::vision::Embedding* mutable_embeddings(int index);
  ::google::protobuf::RepeatedPtrField< ::tflite::task::vision::Embedding >*
      mutable_embeddings();
  private:
  const ::google::protobuf::RepeatedPtrField<::tflite::task::vision::Embedding>& _internal_embeddings() const;
  ::google::protobuf::RepeatedPtrField<::tflite::task::vision::Embedding>* _internal_mutable_embeddings();
  public:
  const ::tflite::task::vision::Embedding& embeddings(int index) const;
  ::tflite::task::vision::Embedding* add_embeddings();
  const ::google::protobuf::RepeatedPtrField< ::tflite::task::vision::Embedding >&
      embeddings() const;
  // @@protoc_insertion_point(class_scope:tflite.task.vision.EmbeddingResult)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<0, 1, 1, 0, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::RepeatedPtrField< ::tflite::task::vision::Embedding > embeddings_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// FeatureVector

// repeated float value_float = 1 [packed = true];
inline int FeatureVector::_internal_value_float_size() const {
  return _internal_value_float().size();
}
inline int FeatureVector::value_float_size() const {
  return _internal_value_float_size();
}
inline void FeatureVector::clear_value_float() {
  _internal_mutable_value_float()->Clear();
}
inline float FeatureVector::value_float(int index) const {
  // @@protoc_insertion_point(field_get:tflite.task.vision.FeatureVector.value_float)
  return _internal_value_float().Get(index);
}
inline void FeatureVector::set_value_float(int index, float value) {
  _internal_mutable_value_float()->Set(index, value);
  // @@protoc_insertion_point(field_set:tflite.task.vision.FeatureVector.value_float)
}
inline void FeatureVector::add_value_float(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _internal_mutable_value_float()->Add(value);
  // @@protoc_insertion_point(field_add:tflite.task.vision.FeatureVector.value_float)
}
inline const ::google::protobuf::RepeatedField<float>& FeatureVector::value_float() const {
  // @@protoc_insertion_point(field_list:tflite.task.vision.FeatureVector.value_float)
  return _internal_value_float();
}
inline ::google::protobuf::RepeatedField<float>* FeatureVector::mutable_value_float() {
  // @@protoc_insertion_point(field_mutable_list:tflite.task.vision.FeatureVector.value_float)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_value_float();
}

inline const ::google::protobuf::RepeatedField<float>& FeatureVector::_internal_value_float() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.value_float_;
}
inline ::google::protobuf::RepeatedField<float>* FeatureVector::_internal_mutable_value_float() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.value_float_;
}

// optional bytes value_string = 2;
inline bool FeatureVector::has_value_string() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void FeatureVector::clear_value_string() {
  _impl_.value_string_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FeatureVector::value_string() const {
  // @@protoc_insertion_point(field_get:tflite.task.vision.FeatureVector.value_string)
  return _internal_value_string();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void FeatureVector::set_value_string(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.value_string_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tflite.task.vision.FeatureVector.value_string)
}
inline std::string* FeatureVector::mutable_value_string() {
  std::string* _s = _internal_mutable_value_string();
  // @@protoc_insertion_point(field_mutable:tflite.task.vision.FeatureVector.value_string)
  return _s;
}
inline const std::string& FeatureVector::_internal_value_string() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.value_string_.Get();
}
inline void FeatureVector::_internal_set_value_string(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.value_string_.Set(value, GetArenaForAllocation());
}
inline std::string* FeatureVector::_internal_mutable_value_string() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.value_string_.Mutable( GetArenaForAllocation());
}
inline std::string* FeatureVector::release_value_string() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:tflite.task.vision.FeatureVector.value_string)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.value_string_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.value_string_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void FeatureVector::set_allocated_value_string(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.value_string_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.value_string_.IsDefault()) {
          _impl_.value_string_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tflite.task.vision.FeatureVector.value_string)
}

// -------------------------------------------------------------------

// Embedding

// optional .tflite.task.vision.FeatureVector feature_vector = 1;
inline bool Embedding::has_feature_vector() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.feature_vector_ != nullptr);
  return value;
}
inline void Embedding::clear_feature_vector() {
  if (_impl_.feature_vector_ != nullptr) _impl_.feature_vector_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const ::tflite::task::vision::FeatureVector& Embedding::_internal_feature_vector() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::tflite::task::vision::FeatureVector* p = _impl_.feature_vector_;
  return p != nullptr ? *p : reinterpret_cast<const ::tflite::task::vision::FeatureVector&>(::tflite::task::vision::_FeatureVector_default_instance_);
}
inline const ::tflite::task::vision::FeatureVector& Embedding::feature_vector() const {
  // @@protoc_insertion_point(field_get:tflite.task.vision.Embedding.feature_vector)
  return _internal_feature_vector();
}
inline void Embedding::unsafe_arena_set_allocated_feature_vector(::tflite::task::vision::FeatureVector* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.feature_vector_);
  }
  _impl_.feature_vector_ = reinterpret_cast<::tflite::task::vision::FeatureVector*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tflite.task.vision.Embedding.feature_vector)
}
inline ::tflite::task::vision::FeatureVector* Embedding::release_feature_vector() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::tflite::task::vision::FeatureVector* released = _impl_.feature_vector_;
  _impl_.feature_vector_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArenaForAllocation() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::tflite::task::vision::FeatureVector* Embedding::unsafe_arena_release_feature_vector() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:tflite.task.vision.Embedding.feature_vector)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::tflite::task::vision::FeatureVector* temp = _impl_.feature_vector_;
  _impl_.feature_vector_ = nullptr;
  return temp;
}
inline ::tflite::task::vision::FeatureVector* Embedding::_internal_mutable_feature_vector() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.feature_vector_ == nullptr) {
    auto* p = CreateMaybeMessage<::tflite::task::vision::FeatureVector>(GetArenaForAllocation());
    _impl_.feature_vector_ = reinterpret_cast<::tflite::task::vision::FeatureVector*>(p);
  }
  return _impl_.feature_vector_;
}
inline ::tflite::task::vision::FeatureVector* Embedding::mutable_feature_vector() {
  ::tflite::task::vision::FeatureVector* _msg = _internal_mutable_feature_vector();
  // @@protoc_insertion_point(field_mutable:tflite.task.vision.Embedding.feature_vector)
  return _msg;
}
inline void Embedding::set_allocated_feature_vector(::tflite::task::vision::FeatureVector* value) {
  ::google::protobuf::Arena* message_arena = GetArenaForAllocation();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::tflite::task::vision::FeatureVector*>(_impl_.feature_vector_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena =
        ::google::protobuf::Arena::InternalGetOwningArena(reinterpret_cast<::tflite::task::vision::FeatureVector*>(value));
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.feature_vector_ = reinterpret_cast<::tflite::task::vision::FeatureVector*>(value);
  // @@protoc_insertion_point(field_set_allocated:tflite.task.vision.Embedding.feature_vector)
}

// optional int32 output_index = 2;
inline bool Embedding::has_output_index() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Embedding::clear_output_index() {
  _impl_.output_index_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::int32_t Embedding::output_index() const {
  // @@protoc_insertion_point(field_get:tflite.task.vision.Embedding.output_index)
  return _internal_output_index();
}
inline void Embedding::set_output_index(::int32_t value) {
  _internal_set_output_index(value);
  // @@protoc_insertion_point(field_set:tflite.task.vision.Embedding.output_index)
}
inline ::int32_t Embedding::_internal_output_index() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.output_index_;
}
inline void Embedding::_internal_set_output_index(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.output_index_ = value;
}

// -------------------------------------------------------------------

// EmbeddingResult

// repeated .tflite.task.vision.Embedding embeddings = 1;
inline int EmbeddingResult::_internal_embeddings_size() const {
  return _internal_embeddings().size();
}
inline int EmbeddingResult::embeddings_size() const {
  return _internal_embeddings_size();
}
inline void EmbeddingResult::clear_embeddings() {
  _internal_mutable_embeddings()->Clear();
}
inline ::tflite::task::vision::Embedding* EmbeddingResult::mutable_embeddings(int index) {
  // @@protoc_insertion_point(field_mutable:tflite.task.vision.EmbeddingResult.embeddings)
  return _internal_mutable_embeddings()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::tflite::task::vision::Embedding >*
EmbeddingResult::mutable_embeddings() {
  // @@protoc_insertion_point(field_mutable_list:tflite.task.vision.EmbeddingResult.embeddings)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_embeddings();
}
inline const ::tflite::task::vision::Embedding& EmbeddingResult::embeddings(int index) const {
  // @@protoc_insertion_point(field_get:tflite.task.vision.EmbeddingResult.embeddings)
    return _internal_embeddings().Get(index);
}
inline ::tflite::task::vision::Embedding* EmbeddingResult::add_embeddings() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::tflite::task::vision::Embedding* _add = _internal_mutable_embeddings()->Add();
  // @@protoc_insertion_point(field_add:tflite.task.vision.EmbeddingResult.embeddings)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField< ::tflite::task::vision::Embedding >&
EmbeddingResult::embeddings() const {
  // @@protoc_insertion_point(field_list:tflite.task.vision.EmbeddingResult.embeddings)
  return _internal_embeddings();
}
inline const ::google::protobuf::RepeatedPtrField<::tflite::task::vision::Embedding>&
EmbeddingResult::_internal_embeddings() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.embeddings_;
}
inline ::google::protobuf::RepeatedPtrField<::tflite::task::vision::Embedding>*
EmbeddingResult::_internal_mutable_embeddings() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.embeddings_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace vision
}  // namespace task
}  // namespace tflite


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_tensorflow_5flite_5fsupport_2fcc_2ftask_2fvision_2fproto_2fembeddings_2eproto_2epb_2eh