#import <UIKit/UIKit.h>

@interface LoginViewController : UITableViewController<UITextFieldDelegate>
@property (nonatomic, retain) IBOutlet UITextField *urlField;
@property (nonatomic, retain) IBOutlet UITextField *usernameField;
@property (nonatomic, retain) IBOutlet UITextField *passwordField;
@end
