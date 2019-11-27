#ifndef ch6_1_h
#define ch6_1_h

// [Page 152]
//   PARENT(i)
//   - Time: O(1)
//
// [Page 152]
//   LEFT(i)
//   - Time: O(1)
//
// [Page 152]
//   RIGHT(i)
//   - Time: O(1)

namespace CLRS {
namespace CH6 {
int parent(int i) { return (i - 1) / 2; }

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }
}  // namespace CH6
}  // namespace CLRS

#endif