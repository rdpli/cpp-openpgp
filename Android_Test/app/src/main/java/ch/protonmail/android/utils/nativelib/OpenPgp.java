// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

/**
 *open_pgp_key_manager = interface +c {
 *    static create_instance() : open_pgp_key_manager;
 *}
 *generat new key with email address. Fix the UserID issue in protonmail system. on Feb 28, 17
 *static generate_key_with_email(email : string, passphrase : string, bits : i32) : open_pgp_key;
 * generate new key
 *static generate_new_key(user_id : string, email : string, passphrase : string, bits : i32) : open_pgp_key;
 */
public abstract class OpenPgp {
    /**add a new address into addresses list */
    public abstract boolean addAddress(@Nonnull Address address);

    /**remove a exsit address from the list based on address id */
    public abstract boolean removeAddress(@Nonnull String addressId);

    /**clean address list */
    public abstract boolean cleanAddresses();

    /**generat new key pair */
    @Nonnull
    public abstract OpenPgpKey generateKey(@Nonnull String userName, @Nonnull String domain, @Nonnull String passphrase, int bits);

    /**
     * old functions blow
     *update the information carried in the packet. //TODO need add more parameters
     */
    public abstract void updatePrivateInfo(@Nonnull String privateKey);

    /**encrypt message */
    @Nonnull
    public abstract String encryptMessage(@Nonnull String addressId, @Nonnull String plainText, @Nonnull String passphras);

    @Nonnull
    public abstract String encryptMessageSingleKey(@Nonnull String publicKey, @Nonnull String plainText, @Nonnull String privateKey, @Nonnull String passphras);

    @Nonnull
    public abstract String decryptMessage(@Nonnull String encryptText, @Nonnull String passphras);

    @Nonnull
    public abstract String decryptMessageSingleKey(@Nonnull String encryptText, @Nonnull String privateKey, @Nonnull String passphras);

    /**for signature */
    @Nonnull
    public abstract EncryptSignPackage encryptMessageSignExternal(@Nonnull String publicKey, @Nonnull String privateKey, @Nonnull String plainText, @Nonnull String passphras);

    @Nonnull
    public abstract DecryptSignVerify decryptMessageVerify(@Nonnull String publicKey, @Nonnull String privateKey, @Nonnull String passphras, @Nonnull String encrypted, @Nonnull String signature);

    @Nonnull
    public abstract String signDetached(@Nonnull String privateKey, @Nonnull String plainText, @Nonnull String passphras);

    public abstract boolean signDetachedVerify(@Nonnull String publicKey, @Nonnull String signature, @Nonnull String plainText);

    @Nonnull
    public abstract EncryptPackage encryptAttachment(@Nonnull String addressId, @Nonnull byte[] unencryptData, @Nonnull String fileName, @Nonnull String passphras);

    @Nonnull
    public abstract EncryptPackage encryptAttachmentSingleKey(@Nonnull String publicKey, @Nonnull byte[] unencryptData, @Nonnull String fileName, @Nonnull String privateKey, @Nonnull String passphras);

    @Nonnull
    public abstract byte[] decryptAttachment(@Nonnull byte[] key, @Nonnull byte[] data, @Nonnull String passphras);

    @Nonnull
    public abstract byte[] decryptAttachmentSingleKey(@Nonnull byte[] key, @Nonnull byte[] data, @Nonnull String privateKey, @Nonnull String passphras);

    @Nonnull
    public abstract byte[] decryptAttachmentWithPassword(@Nonnull byte[] key, @Nonnull byte[] data, @Nonnull String password);

    @Nonnull
    public abstract byte[] getPublicKeySessionKey(@Nonnull byte[] keyPackage, @Nonnull String passphrase);

    @Nonnull
    public abstract byte[] getPublicKeySessionKeySingleKey(@Nonnull byte[] keyPackage, @Nonnull String privateKey, @Nonnull String passphrase);

    @Nonnull
    public abstract byte[] getSymmetricSessionKey(@Nonnull byte[] keyPackage, @Nonnull String password);

    @Nonnull
    public abstract byte[] getNewPublicKeyPackage(@Nonnull byte[] session, @Nonnull String publicKey);

    @Nonnull
    public abstract byte[] getNewSymmetricKeyPackage(@Nonnull byte[] session, @Nonnull String password);

    @Nonnull
    public abstract String encryptMessageAes(@Nonnull String plainText, @Nonnull String password);

    @Nonnull
    public abstract String decryptMessageAes(@Nonnull String encryptedMessage, @Nonnull String password);

    @Nonnull
    public abstract String encryptMailboxPwd(@Nonnull String unencryptedPwd, @Nonnull String salt);

    @Nonnull
    public abstract String decryptMailboxPwd(@Nonnull String encryptedPwd, @Nonnull String salt);

    @Nonnull
    public abstract String readClearsignedMessage(@Nonnull String signedMessage);

    /**test functions */
    public abstract int throwAnException();

    /**PBE */
    @Nonnull
    public abstract String encryptHashCbc(@Nonnull String plainText, @Nonnull String password);

    @Nonnull
    public abstract String decryptHashCbc(@Nonnull String encryptedText, @Nonnull String password);

    /**
     * create and init an instance those instance have addresses manager build in
     * if want deal with single key should use the static functions
     */
    @CheckForNull
    public static native OpenPgp createInstance();

    /** create and init an instance with addresses */
    @CheckForNull
    public static native OpenPgp createInstanceWithAddress(@Nonnull Address address);

    @CheckForNull
    public static native OpenPgp createInstanceWithAddresses(@Nonnull ArrayList<Address> address);

    /**update single private key password */
    @Nonnull
    public static native String updateSinglePassphrase(@Nonnull String privateKey, @Nonnull String oldPassphrase, @Nonnull String newPassphrase);

    /**disable/enable debug model */
    public static native void enableDebug(boolean isDebug);

    /**check is private key passphrase ok */
    public static native boolean checkPassphrase(@Nonnull String privateKey, @Nonnull String passphrase);

    /**update multiple pgp private keys return are new keys */
    @Nonnull
    public static native ArrayList<OpenPgpKey> updateKeysPassphrase(@Nonnull ArrayList<OpenPgpKey> privateKeys, @Nonnull String oldPassphrase, @Nonnull String newPassphrase);

    /**decrypt message use the address key ring with password */
    @Nonnull
    public static native String decryptMessageWithAddress(@Nonnull Address address, @Nonnull String encryptText, @Nonnull String passphras);

    /**decrypt attachment use the address key ring with password */
    @Nonnull
    public static native byte[] decryptAttachmentWithAddress(@Nonnull Address address, @Nonnull byte[] key, @Nonnull byte[] data, @Nonnull String passphras);

    /**Random bits */
    @Nonnull
    public static native byte[] randomBits(int bits);

    private static final class CppProxy extends OpenPgp
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public boolean addAddress(Address address)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_addAddress(this.nativeRef, address);
        }
        private native boolean native_addAddress(long _nativeRef, Address address);

        @Override
        public boolean removeAddress(String addressId)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_removeAddress(this.nativeRef, addressId);
        }
        private native boolean native_removeAddress(long _nativeRef, String addressId);

        @Override
        public boolean cleanAddresses()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_cleanAddresses(this.nativeRef);
        }
        private native boolean native_cleanAddresses(long _nativeRef);

        @Override
        public OpenPgpKey generateKey(String userName, String domain, String passphrase, int bits)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_generateKey(this.nativeRef, userName, domain, passphrase, bits);
        }
        private native OpenPgpKey native_generateKey(long _nativeRef, String userName, String domain, String passphrase, int bits);

        @Override
        public void updatePrivateInfo(String privateKey)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_updatePrivateInfo(this.nativeRef, privateKey);
        }
        private native void native_updatePrivateInfo(long _nativeRef, String privateKey);

        @Override
        public String encryptMessage(String addressId, String plainText, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptMessage(this.nativeRef, addressId, plainText, passphras);
        }
        private native String native_encryptMessage(long _nativeRef, String addressId, String plainText, String passphras);

        @Override
        public String encryptMessageSingleKey(String publicKey, String plainText, String privateKey, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptMessageSingleKey(this.nativeRef, publicKey, plainText, privateKey, passphras);
        }
        private native String native_encryptMessageSingleKey(long _nativeRef, String publicKey, String plainText, String privateKey, String passphras);

        @Override
        public String decryptMessage(String encryptText, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptMessage(this.nativeRef, encryptText, passphras);
        }
        private native String native_decryptMessage(long _nativeRef, String encryptText, String passphras);

        @Override
        public String decryptMessageSingleKey(String encryptText, String privateKey, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptMessageSingleKey(this.nativeRef, encryptText, privateKey, passphras);
        }
        private native String native_decryptMessageSingleKey(long _nativeRef, String encryptText, String privateKey, String passphras);

        @Override
        public EncryptSignPackage encryptMessageSignExternal(String publicKey, String privateKey, String plainText, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptMessageSignExternal(this.nativeRef, publicKey, privateKey, plainText, passphras);
        }
        private native EncryptSignPackage native_encryptMessageSignExternal(long _nativeRef, String publicKey, String privateKey, String plainText, String passphras);

        @Override
        public DecryptSignVerify decryptMessageVerify(String publicKey, String privateKey, String passphras, String encrypted, String signature)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptMessageVerify(this.nativeRef, publicKey, privateKey, passphras, encrypted, signature);
        }
        private native DecryptSignVerify native_decryptMessageVerify(long _nativeRef, String publicKey, String privateKey, String passphras, String encrypted, String signature);

        @Override
        public String signDetached(String privateKey, String plainText, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_signDetached(this.nativeRef, privateKey, plainText, passphras);
        }
        private native String native_signDetached(long _nativeRef, String privateKey, String plainText, String passphras);

        @Override
        public boolean signDetachedVerify(String publicKey, String signature, String plainText)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_signDetachedVerify(this.nativeRef, publicKey, signature, plainText);
        }
        private native boolean native_signDetachedVerify(long _nativeRef, String publicKey, String signature, String plainText);

        @Override
        public EncryptPackage encryptAttachment(String addressId, byte[] unencryptData, String fileName, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptAttachment(this.nativeRef, addressId, unencryptData, fileName, passphras);
        }
        private native EncryptPackage native_encryptAttachment(long _nativeRef, String addressId, byte[] unencryptData, String fileName, String passphras);

        @Override
        public EncryptPackage encryptAttachmentSingleKey(String publicKey, byte[] unencryptData, String fileName, String privateKey, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptAttachmentSingleKey(this.nativeRef, publicKey, unencryptData, fileName, privateKey, passphras);
        }
        private native EncryptPackage native_encryptAttachmentSingleKey(long _nativeRef, String publicKey, byte[] unencryptData, String fileName, String privateKey, String passphras);

        @Override
        public byte[] decryptAttachment(byte[] key, byte[] data, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptAttachment(this.nativeRef, key, data, passphras);
        }
        private native byte[] native_decryptAttachment(long _nativeRef, byte[] key, byte[] data, String passphras);

        @Override
        public byte[] decryptAttachmentSingleKey(byte[] key, byte[] data, String privateKey, String passphras)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptAttachmentSingleKey(this.nativeRef, key, data, privateKey, passphras);
        }
        private native byte[] native_decryptAttachmentSingleKey(long _nativeRef, byte[] key, byte[] data, String privateKey, String passphras);

        @Override
        public byte[] decryptAttachmentWithPassword(byte[] key, byte[] data, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptAttachmentWithPassword(this.nativeRef, key, data, password);
        }
        private native byte[] native_decryptAttachmentWithPassword(long _nativeRef, byte[] key, byte[] data, String password);

        @Override
        public byte[] getPublicKeySessionKey(byte[] keyPackage, String passphrase)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPublicKeySessionKey(this.nativeRef, keyPackage, passphrase);
        }
        private native byte[] native_getPublicKeySessionKey(long _nativeRef, byte[] keyPackage, String passphrase);

        @Override
        public byte[] getPublicKeySessionKeySingleKey(byte[] keyPackage, String privateKey, String passphrase)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPublicKeySessionKeySingleKey(this.nativeRef, keyPackage, privateKey, passphrase);
        }
        private native byte[] native_getPublicKeySessionKeySingleKey(long _nativeRef, byte[] keyPackage, String privateKey, String passphrase);

        @Override
        public byte[] getSymmetricSessionKey(byte[] keyPackage, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSymmetricSessionKey(this.nativeRef, keyPackage, password);
        }
        private native byte[] native_getSymmetricSessionKey(long _nativeRef, byte[] keyPackage, String password);

        @Override
        public byte[] getNewPublicKeyPackage(byte[] session, String publicKey)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getNewPublicKeyPackage(this.nativeRef, session, publicKey);
        }
        private native byte[] native_getNewPublicKeyPackage(long _nativeRef, byte[] session, String publicKey);

        @Override
        public byte[] getNewSymmetricKeyPackage(byte[] session, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getNewSymmetricKeyPackage(this.nativeRef, session, password);
        }
        private native byte[] native_getNewSymmetricKeyPackage(long _nativeRef, byte[] session, String password);

        @Override
        public String encryptMessageAes(String plainText, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptMessageAes(this.nativeRef, plainText, password);
        }
        private native String native_encryptMessageAes(long _nativeRef, String plainText, String password);

        @Override
        public String decryptMessageAes(String encryptedMessage, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptMessageAes(this.nativeRef, encryptedMessage, password);
        }
        private native String native_decryptMessageAes(long _nativeRef, String encryptedMessage, String password);

        @Override
        public String encryptMailboxPwd(String unencryptedPwd, String salt)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptMailboxPwd(this.nativeRef, unencryptedPwd, salt);
        }
        private native String native_encryptMailboxPwd(long _nativeRef, String unencryptedPwd, String salt);

        @Override
        public String decryptMailboxPwd(String encryptedPwd, String salt)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptMailboxPwd(this.nativeRef, encryptedPwd, salt);
        }
        private native String native_decryptMailboxPwd(long _nativeRef, String encryptedPwd, String salt);

        @Override
        public String readClearsignedMessage(String signedMessage)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_readClearsignedMessage(this.nativeRef, signedMessage);
        }
        private native String native_readClearsignedMessage(long _nativeRef, String signedMessage);

        @Override
        public int throwAnException()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_throwAnException(this.nativeRef);
        }
        private native int native_throwAnException(long _nativeRef);

        @Override
        public String encryptHashCbc(String plainText, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_encryptHashCbc(this.nativeRef, plainText, password);
        }
        private native String native_encryptHashCbc(long _nativeRef, String plainText, String password);

        @Override
        public String decryptHashCbc(String encryptedText, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_decryptHashCbc(this.nativeRef, encryptedText, password);
        }
        private native String native_decryptHashCbc(long _nativeRef, String encryptedText, String password);
    }
}
