/**
 * @file hello.h
 * @author  roy4801 <roy@rish.com.tw>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option)any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Example class
 * Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus egestas erat nec nulla placerat venenatis.
 * Proin a libero ac sapien mattis facilisis. Morbi nunc dui, rutrum nec condimentum at, volutpat vel odio.
 * Vivamus pharetra purus ac diam condimentum convallis. Proin lacinia vulputate leo ut ultricies.
 */

#pragma once

/**
 * @brief Example class
 * @details Morbi accumsan ipsum vel nisl interdum egestas. Praesent eros massa, convallis et congue vel,
 *          porttitor vitae turpis. Phasellus venenatis lectus tellus, et scelerisque nisi dapibus nec.
 */
class Example
{
public:
    /**
    * Constructor that sets the time to a given value.
    *
    * Detail texts
    * @param i inpout
    */
    Example(int i)
    {
    }

    /**
     * @brief Destroy the Example object
     */
    ~Example()
    {
    }

    /**
    * Get the current time.
    *
    * @return Example& A example object.
    */
    static Example& now()
    {
    }

    /**
     * @brief Example `enum` type
     * @details 衣是古底的生地法任的受公。油獨說種來教紀眾？我不一？
     *          家農回不神下將中打體工區商資母我案照中例紅人而空臺這本裡治無裡！
     */
    enum ExampleType
    {
        //! Lorem ipsum dolor sit amet
        ExType1,

        //! consectetur adipiscing elit
        ExType2,

        //! Sed mi ex, congue ut lacinia vitae
        ExTypeCount
    };

    /**
     * @brief Example of another style of single line comment
     */
    enum ExampleAnotherType
    {
        ExaType1,    //!< Nullam ac porttitor velit.
        ExaType2,    //!< Maecenas consectetur egestas ex sit amet sodales.
        ExaTypecount //!< Maecenas nec elementum augue, in fermentum leo.
                     //!< Praesent non laoreet ante. Aliquam et neque molestie, consectetur sapien id, efficitur lorem.
    };

    /**
     * @brief Example struct
     *
     */
    struct ExampleStruct
    {
        /**
         * @brief Attribute a
         * @details Some documentation for the member BoxStruct#a.
         */
        int a;

        /**
         * @brief Attribute b
         * @details Some documentation for the member BoxStruct#b.
         */
        float b;

        /**
         * @brief Attribute c
         * @details Some documentation for the member BoxStruct#c.
         */
        double c;
    };

    /**
     * @brief Example showing how to document a function with Doxygen.
     *
     * Description of what the function does. This part may refer to the parameters
     * of the function, like @p param1 or @p param2. A word of code can also be
     * inserted like @c this which is equivalent to <tt>this</tt> and can be useful
     * to say that the function returns a @c void or an @c int. If you want to have
     * more than one word in typewriter font, then just use @<tt@>.
     * We can also include text verbatim,
     * @verbatim like this@endverbatim
     * Sometimes it is also convenient to include an example of usage:
     * @code
     * BoxStruct *out = Box_The_Function_Name(param1, param2);
     * printf("something...\n");
     * @endcode
     * Or,
     * @code{.py}
     * pyval = python_func(arg1, arg2)
     * print pyval
     * @endcode
     * when the language is not the one used in the current source file (but
     * <b>be careful</b> as this may be supported only by recent versions
     * of Doxygen). By the way, <b>this is how you write bold text</b> or,
     * if it is just one word, then you can just do @b this.
     * @param param1 Description of the first parameter of the function.
     * @param param2 The second one, which follows @p param1.
     * @return Describe what the function returns.
     * @see first
     * @see Box_The_Last_One
     * @see http://website/
     * @note Something to note.
     * @warning Warning.
     */
    void example()
    {
    }

    /**
     * @brief A simple stub function to show how links do work.
     *
     * Links are generated automatically for webpages (like http://www.google.co.uk)
     * and for structures, like ExampleStruct. For typedef-ed types use
     * #ExampleStruct.
     * For functions, automatic links are generated when the parenthesis () follow
     * the name of the function, like example().
     * Alternatively, you can use #example.
     * @return @c NULL is always returned.
     */
    void first()
    {
    }

    /**
     * Brief can be omitted. If you configure Doxygen with
     * <tt>JAVADOC_AUTOBRIEF=YES</tt>, then the first Line of the comment is used
     * instead. In this function this would be as if
     * @verbatim @brief Brief can be omitted. @endverbatim
     * was used instead.
     */
    void second()
    {
    }
};
