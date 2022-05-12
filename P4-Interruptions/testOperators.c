int age, gender, height, packed_info;


packed_info = (age << 8) | (gender << 7) | height;

// Unpack with shifts and masking using "and"
height = packed_info & 0x7F;   // This constant is binary ...01111111
gender = (packed_info >> 7) & 1;
age    = (packed_info >> 8);

printf(packed_info)