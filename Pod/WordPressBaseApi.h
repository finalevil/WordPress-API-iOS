#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol WordPressBaseApi <NSObject>

///-----------------------
/// @name Quick Publishing
///-----------------------

/**
 Publishes a post asynchronously with text/HTML only

 All the parameters are optional, and can be set to `nil`

 @param content The post content/body. It can be text only or HTML, but be aware that some HTML might be stripped in WordPress. [What's allowed in WordPress.com?](http://en.support.wordpress.com/code/)
 @param title The post title.
 @param success A block object to execute when the method successfully publishes the post. This block has no return value and takes two arguments: the resulting post ID, and the permalink (or [shortlink](http://en.support.wordpress.com/shortlinks/) if available).
 @param failure A block object to execute when the method can't publish the post. This block has no return value and takes one argument: a NSError object with details on the error.
 */
- (void)publishPostWithText:(NSString *)content
                      title:(NSString *)title
                    success:(void (^)(NSUInteger postId, NSURL *permalink))success
                    failure:(void (^)(NSError *error))failure;

/**
 Publishes a post asynchronously with an image

 All the parameters are optional, and can be set to `nil`

 @warning **Not implemented yet**. It just calls publishPostWIthText:title:success:failure: ignoring the image
 @param image An image to add to the post. The image will be embedded **before** the content.
 @param content The post content/body. It can be text only or HTML, but be aware that some HTML might be stripped in WordPress. [What's allowed in WordPress.com?](http://en.support.wordpress.com/code/)
 @param title The post title.
 @param success A block object to execute when the method successfully publishes the post. This block has no return value and takes two arguments: the resulting post ID, and the permalink (or [shortlink](http://en.support.wordpress.com/shortlinks/) if available).
 @param failure A block object to execute when the method can't publish the post. This block has no return value and takes one argument: a NSError object with details on the error.
 */
- (void)publishPostWithImage:(UIImage *)image
                 description:(NSString *)content
                       title:(NSString *)title
                     success:(void (^)(NSUInteger postId, NSURL *permalink))success
                     failure:(void (^)(NSError *error))failure;

/**
 Publishes a post asynchronously with an image gallery

 All the parameters are optional, and can be set to `nil`

 @warning **Not implemented yet**. It just calls publishPostWIthText:title:success:failure: ignoring the images
 @param images An array containing images (as UIImage) to add to the post. The gallery will be embedded **before** the content using the [[gallery]](http://en.support.wordpress.com/images/gallery/) shortcode.
 @param content The post content/body. It can be text only or HTML, but be aware that some HTML might be stripped in WordPress. [What's allowed in WordPress.com?](http://en.support.wordpress.com/code/)
 @param title The post title.
 @param success A block object to execute when the method successfully publishes the post. This block has no return value and takes two arguments: the resulting post ID, and the permalink (or [shortlink](http://en.support.wordpress.com/shortlinks/) if available).
 @param failure A block object to execute when the method can't publish the post. This block has no return value and takes one argument: a NSError object with details on the error.
 */
- (void)publishPostWithGallery:(NSArray *)images
                   description:(NSString *)content
                         title:(NSString *)title
                       success:(void (^)(NSUInteger postId, NSURL *permalink))success
                       failure:(void (^)(NSError *error))failure;


///---------------------
/// @name Managing posts
///---------------------

/**
 Get a list of the recent posts

 @param count Number of recent posts to get
 @param success A block object to execute when the method successfully publishes the post. This block has no return value and takes one argument: an array with the latest posts.
 @param failure A block object to execute when the method can't publish the post. This block has no return value and takes one argument: a NSError object with details on the error.
 */
- (void)getPosts:(NSUInteger)count
         success:(void (^)(NSArray *posts))success
         failure:(void (^)(NSError *error))failure;

//Get all category
- (void)getCategory:(void (^)(NSMutableArray *categoryList))success failure:(void (^)(NSError *))failure;

//publish post with category and tags
- (void)publishPostWithText:(NSString *)content title:(NSString *)title WithCategoryName:(NSString *)categoryName WithTags:(NSMutableArray*)tags WithPostStatus:(NSString*)postStatus success:(void (^)(NSUInteger postId, NSURL *url))success failure:(void (^)(NSError *error))failure;


//add new tag
- (void)addTag:(NSString *)tagName success:(void (^)(NSUInteger tagId))success failure:(void (^)(NSError *error))failure;

//edit post
- (void)editPostWithPostId:(NSString *)postId WithContent:(NSString *)content title:(NSString *)title WithCategoryName:(NSString *)categoryName WithTags:(NSMutableArray*)tags WithFeatureImageAttachmentId:(NSString*)featureImageAttachmentId success:(void (^)(NSUInteger postId, NSURL *url))success failure:(void (^)(NSError *error))failure;

//upload image file
-(void)uploadImageWithImageName:(NSString*)imageName WithMimeType:(NSString*)mimeType WithImageData:(NSData*)imageData WithOverwrite:(BOOL)overwrite success:(void (^)(NSString *attachmentId, NSURL *url))success failure:(void (^)(NSError *error))failure;

//delete post, delete media
- (void)deletePostWithPostId:(NSString *)postId success:(void (^)(bool success, NSURL *url))success failure:(void (^)(NSError *error))failure;

@end
