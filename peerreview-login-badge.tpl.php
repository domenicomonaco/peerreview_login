<?php
// $Id:$

/**
 * Author Domenico Monaco
 * kiuz.4ever@gmail.com
 * http://www.kiuz.it
 * License: GPLv2
 **/

?>
<div class="palette">

<div id="block_box">
  <?php print theme('peerreview_login_wizard_box'); ?>
</div>

<div class="badge">
<?php
  if(isset($pre)){
    print $pre;
  }
  
  if(isset($middle)){
    print $middle;
  }
  
  if(isset($post)){
    print $post;
  }
?>
</div>
</div>
